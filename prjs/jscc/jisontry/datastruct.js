var ds=(function(){
        
        var ds={};

// AST Classes
//
//  
   
	ds.TranslationUnit=function(){
             this.list=[];
	}
	ds.TranslationUnit.prototype={
		init:function(ed){
			     this.list=[ed];
			     return this;
		},append:function(ed){
			this.list.push(ed);
		},accept:function(visitor){
			visitor.visitTranslationUnit(this);
		}
	}
       
        ds.ExternalDeclaration=function(){

	};
        ds.ExternalDeclaration.prototype={
		init:function(dec){
			     this.dec=dec;
			     return this;
		     },
		accept:function(visitor){
			       visitor.visitExternalDeclaration(this);
		       }
		     
	};
	ds.Declarator=function(){};
    ds.Declarator.prototype={
		init:function(dec){
			this.dec=dec;
			return this;
		},
        accept:function(visitor){
		     visitor.visitDeclarator(this);
        }		
	};
	ds.DirectDeclarator=function(){};
    ds.DirectDeclarator.prototype={
		init:function(p1,p2){
			this.part1=p1;
			this.part2=p2;
			return this;
		}		     
	};
	ds.FunctionDeclarator=function(){};
	
	ds.FunctionDeclarator.prototype={
	
	    init:function(p1,p2){
		    this.name = p1;
			this.params=p2;
			return this;
		},
	    accept:function(visitor){
	        visitor.visitFunctionDeclarator(this);
	    }
	
	}
        ds.FunctionDefinition=function(){};
	ds.FunctionDefinition.prototype={
		init:function(declaration_specifiers, declarator,declaration_list,compound_statement){
			     this.declaration_specifiers = declaration_specifiers;
			     this.declarator = declarator;
			     this.declaration_list=declaration_list;
			     this.compound_statement = compound_statement;

			     return this;
		     },accept:function(visitor){
			     visitor.visitFunctionDefinition(this);
		     }
	}
	
	 ds.DeclarationSpecifiers=function(){};
	 ds.DeclarationSpecifiers.prototype={
	     init:function(typeOrStorageClassSpecifier){
		     this.list=[typeOrStorageClassSpecifier];
			 return this;
		 },
		 append:function(typeOrStorageClassSpecifier){
		     this.list.push(typeOrStorageClassSpecifier);
			 return this;
		 }
	 };

     ds.DeclarationList=function(){};
	 ds.DeclarationList.prototype={
	     init:function(item){
		     this.list=item?[item]:[];
			 return this;
		 },
		 append:function(item){
		     this.list.push(item);
			 return this;
		 },
		 accept:function(visitor){
		     
		 }
	 };
	 ds.StatementList=function(){};
	 ds.StatementList.prototype={
	     init:function(item){
		     this.list=item?[item]:[];
			 return this;
		 },
		 append:function(item){
		     this.list.push(item);
			 return this;
		 },
		 accept:function(visitor){
		     visitor.visitStatementList(this);
		 }
	 };
ds.CompoundStatement=function(){};
    ds.CompoundStatement.prototype={
		init:function(p1,p2){
			this.part1=p1;
			this.part2=p2;
			return this;
		},
         accept:function(visitor){
		     visitor.visitCompoundStatement(this);
		 }		
	};

 ds.Dispatch=function(){};
 ds.Dispatch.prototype={
      init:function(expr,args){
	      this.expr = expr;
		  this.args=args;
		   return this;
	  },
	  accept:function(visitor){
	      visitor.visitDispatch(this);
	  }
 };

 ds.Identifier=function(){};
 ds.Identifier.prototype={
      init:function(id){
	      this.id = id;
		  return this;
	  },
	  accept:function(visitor){
	      visitor.visitIdentifier(this);
	  }
 };
 ds.Constant=function(){};
 ds.Constant.prototype={
      init:function(constant){
	      this.constant = constant;
		   return this;
	  },
	  accept:function(visitor){
	      visitor.visitConstant(this);
	  }
 };
 ds.StringLiteral=function(){};
 ds.StringLiteral.prototype={
      init:function(str){
	      this.str = str;
		   return this;
	  },
	  accept:function(visitor){
	      visitor.visitStringLiteral(this);
	  }
 };
	return ds;
})();


