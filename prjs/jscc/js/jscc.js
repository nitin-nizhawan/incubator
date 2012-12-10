var JSCC=(function(){
   var keywords=["int"];
   var keywordsMap={"int":true};
   function isKeyword(word){
       return !!keywordsMap[word];
   }
   function SymbolTable(){
   }
   SymbolTable.prototype={
       init:function(){
	       this.list=[];
	   },
	   enterScope:function(){
	       this.list.push([]);
	   },
	   exitScope:function(){
	       this.list.pop();
	   },
	   add:function(id,val){
	       this.list[this.list.length-1].push({id:id,val:val});
	   }
   };
   function Mem(){
   }
   Mem.prototype={
       init:function(size){
	       this.mem=[];
		   this.size=size;
		   for(var i=0;i<size;i++){
		       this.mem[i]=0;
		   }
	   },
	   writeByte:function(addr,data){
	       this.mem[addr]=data;
	   },
	   readByte:function(addr){
	       return this.mem[addr];
	   }
   };
   var mem = new Mem().init(64*1024); //64KB
   return {
       exec:function(src){
	       var pos=0;
		   var tokStr="";
		   var tokenArray=[];
		   var symTbl = new SymbolTable().init();
		   symTbl.enterScope(); // the program scope
		   while(pos<src.length){
		       if(src[pos]==' ') {
			      if(tokStr.length>0){
				     if(isKeyword[tokStr]){
					     tokenArray.push(tokStr); tokStr="";
					 } else if(tokStr.matches(/[a-zA-Z][0-9a-zA-Z]*/)){ // identifier
					     if(tokenArray[length-1]=="int"){ // looks like a definition
						     symTbl.add(tokStr,'');
						 }
					 }
				  }
			      pos++;continue;
			   } else if(src[pos]=='"'){
			       var beg = pos; pos++;
			       while(src[pos]!='"'){
				       
				   }
				   tokenArray.push(src.substring(beg,pos+1));
				   pos++;
			   } else if(src[pos]=='{'){
			       symTbl.enterScope();pos++;
			   } else if(src[pos]=='}'){
			       symTbl.exitScope(); pos++;
			   }
			   tokStr+=src[pos++];
			   
		   }
		   
		   symTbl.exitScope();
	   }
   }   













})();