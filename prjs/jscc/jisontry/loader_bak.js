function Loader(){
}
Loader.prototype={
    init:function(code,cpu){
	   this._code = code;
	   this._cpu = cpu;
	   var i;
	   for(i=0;i<code.length;i++){
	       this._cpu.writeMem(i,code[i]);
	   }
	   
	}
	
};