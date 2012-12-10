function SymbolTable(){
   }
   SymbolTable.prototype={
       init:function(){
	       this.list=[];
		   return this;
	   },
	   enterScope:function(){
	       this.list.push({});
	   },
	   exitScope:function(){
	       this.list.pop();
	   },
	   add:function(id,val){
	       this.list[this.list.length-1][id]=val;
	   },
	   lookup:function(id){
	       this.list[this.list.length-1][id];
	   },
	   find:function(id){
	       for(var i=this.list.length-1;i>=0;i--){
		       if(this.list[i][id]){
			       return this.list[i][id];
			   }
		   }
	   }
   };




// Code Generator Visitor
    
	
	CodeGenVisitor=function(){};
	CodeGenVisitor.prototype={
	    IS:CPU.InstructionSet.NameToCode,
	    instrMap:{
		    ld:65,
			ldi:66,
			mv:64,
		    push:69,
			pop:70,
			call:192,
			ret:193,
			jmp:194
		},
		regMap:{
		    "$ra":29,
			"$pc":30,
			"$a":0,
			"$b":1,
			"$sp":3,
			"$fp":4
		},
		stringMap:{},
		init:function(){
		         this.code=[];
				 this.data=[];
				 this._dataPointer=0;
				 this.typeST = new SymbolTable().init();
				 this.valST  = new SymbolTable().init();
				 this.symTab = this.valST;
			     return this;
		     },
			 getCode:function(){
			     return [this.code,this.data];
			 },
             visitTranslationUnit:function(node){
			              this.typeST.enterScope();
						  this.valST.enterScope();
						  this.valST.add("__sscall_",{type:'global'});
					     for(var i=0;i<node.list.length;i++){
						     node.list[i].accept(this);
					     }
		                  this.typeST.exitScope();
						  this.valST.exitScope();
	        },
		    visitExternalDeclaration:function(obj){
						 obj.dec.accept(this);
			},
			visitFunctionDefinition:function(obj){
			    obj.declarator.accept(this);
				obj.compound_statement.accept(this);
			},
			visitDeclarator:function(obj){
			    obj.dec.accept(this);
			},
			nativeTypes:{
			    INT:{size:4,inc:1},
				CHAR:{size:1,inc:1},
				POINTER_TO_INT:{size:4,inc:4},
				POINTER_TO_CHAR:{size:4,inc:1},
				POINTER_TO_POINTER:{size:4,inc:4}
			},
			visitFunctionDeclarator:function(obj){
			    this.valST.add(obj.name,{type:'global'});
				this.code.push({gdef:obj.name});
				if(obj.params){ // params
				   var stackOffset=2;// one for ra and one for fp
				   var totalargsize=0;
				   var sizes=[];
				   for(var i=0;i<obj.params.length;i++){
				        var decSpec = obj.params[i][0];
						var declarator = obj.params[i][1];
						var paramType=decSpec.list[0];
						var nType;
					    if(paramType=="char"&&declarator.length<2){
						    nType=this.nativeTypes.CHAR;
							totalargsize+=nType.size;
							sizes.push(nType.size);
						} else if(paramType=="char"&&declarator.length<3){
						    nType=this.nativeTypes.POINTER_TO_CHAR;
							totalargsize+=nType.size;
							sizes.push(nType.size);
						} else if(paramType=="int"&&declarator.length<2){
						    nType = this.nativeTypes.INT;
							totalargsize+=nType.size;
							sizes.push(nType.size);
						}
				   }
				   var offsets=0;
				   for(var i=0;i<obj.params.length;i++){
				       var decSpec = obj.params[i][0];
						var declarator = obj.params[i][1];
				       this.valST.add(declarator[declarator.length-1],{offset:offsets});
					   totalargsize-=sizes[i];
					   offsets+=sizes[i];
					  
				   }
				   
				   
				}
			},
			visitCompoundStatement:function(obj){
			    this.valST.enterScope();
				this.typeST.enterScope();
				this.code.push(this.IS["mv"],this.regMap["$a"],this.regMap["$sp"]);
				this.code.push(this.IS["push_dw"],this.regMap["$ra"]);
				this.code.push(this.IS["push_dw"],this.regMap["$fp"]);
				this.code.push(this.IS["mv"],this.regMap["$fp"],this.regMap["$a"]); // establishes frame pointer for this scope
				 obj.part1.accept(this);
				 obj.part2.accept(this);
				 this.code.push(this.IS["pop_dw"],this.regMap["$fp"]);
				 this.code.push(this.IS["pop_dw"],this.regMap["$ra"]);
				 this.code.push(this.instrMap["ret"]);
				this.typeST.exitScope();
				this.valST.exitScope();
			},
			visitDeclarationList:function(obj){
			},
			visitStatementList:function(obj){
			    for(var i=0;i<obj.list.length;i++){
				    obj.list[i].accept(this);
				}
			},
			visitDispatch:function(obj){
			    var argsize=[];
				// set frame pointer to stack pointer 
				// fp and ra are callee saved.
				//this.code.push(this.instrMap["mv"],this.regMap["$fp"],this.regMap["$sp"]);
				var arg_size=0;
				for(var i=obj.args.length-1;i>=0;i--){
				    obj.args[i].accept(this);
					this.code.push(this.IS.push_dw,0); 
					arg_size+=4;
				}
				obj.expr.accept(this);
				this.code.push(this.instrMap["call"],this.regMap["$a"]);
				
				// restore stack
				this.code.push(this.IS['ldi_dw'],this.regMap["$a"],arg_size&0xFF,arg_size>>>8&0xFF,arg_size>>>16&0xFF,arg_size>>>24&0xFF);
				this.code.push(this.IS['add'],this.regMap["$sp"],this.regMap["$a"]);
			//	this.code.push(this.instrMap["mv"],this.regMap["$sp"],this.regMap["$fp"]);
				/*for(var i=obj.args.length-1;i>=0;i--){
					this.code.push(this.instrMap["pop"],0); 
				}*/
				//this.code.push(this.instrMap["ldi"],this.regMap["$a"],20);
				//this.code.push(128,3,0);
			},
			visitIdentifier:function(obj){
			     var def = this.symTab.find(obj.id);
				 if(!def){
				    throw new Error("Variable "+obj.id+"not defined");
				 }else  if(def.type=='global'){
			        this.code.push(this.instrMap["ldi"],this.regMap["$a"],{ref:obj.id},0,0,0);
				 } else {
				    var offset = def.offset;
				    this.code.push(this.IS.mv,this.regMap["$a"],this.regMap["$fp"]);
					this.code.push(this.IS.ldi_dw,this.regMap["$b"],offset&0xFF,offset>>>8&0xFF,offset>>>16&0xFF,offset>>>24&0xFF);
					this.code.push(this.IS.add,this.regMap["$a"],this.regMap["$b"]);
					this.code.push(this.IS.ldin_dw,this.regMap["$a"],this.regMap["$a"]);
				 }
				//this.code.push(this.instrMap["push"],this.regMap["$a"]);
			},
			getUniqueName:function(){
			   this._uniqueId = (this._uniqueId||0)+1;
			   return "__u"+this._uniqueId;
			},
			visitConstant:function(obj){
			/*    this.code.push(this.instrMap["ldi"],0,0,0,0,0);
				this.code.push(this.instrMap["push"],0);
				this.code.push(this.instrMap["ldi"],0,0,0,0,0);
				this.code.push(this.instrMap["push"],0);
				this.code.push(this.instrMap["ldi"],0,0,0,0,0);
				this.code.push(this.instrMap["push"],0);*/
				var num = parseInt(obj.constant);
				this.code.push(this.IS.ldi_dw,0,num&0xFF,(num>>>8)&0xFF,(num>>>16)&0xFF,(num>>>24)&0xFF);
				//this.code.push(this.instrMap["push"],0);
				
			},
			visitStringLiteral:function(obj){
			    //push null pointer
				//if(!this.stringMap[obj.str]){
				    var uniq = this.getUniqueName();
					//this.stringMap[obj.str]=uniq;
				//} 
				this.data.push({def:uniq});
			    for(var i=0;i<obj.str.length;i++){
				    this.data.push(obj.str.charCodeAt(i));
				}
				this.data.push(0); // null character
				this.code.push(this.IS.ldi_dw,0,{ref:uniq},0,0,0);
			}
	};