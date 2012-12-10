// process next intruction
function CPU(){
}
CPU.prototype={
     init:function(memSize,inStr,outStr){
	     this._instrMap={};
		 this._inStream  = inStr;
		 this._outStream = outStr;
		 this._mem=new Array(memSize);
		 var misc=[
		       [this._nop,1],/*0*/  // just increments the program counter 
			   [this._syscall,1], /*1*/
			   [this._halt,1] /*2*/
			 ];
			 // data move instructions
		 var data_mov=
       		[ 
			  [this._mv,3],/*256*/  // mv dadr,sadr // moves word from sadr to sadr
			  [this._ld,3],/*257*/  
			  [this._ldi,3], /*258*/
			  [this._st,3], /*259*/
			  [this._sti,3], /*260*/
			  [this._pushr,2],/*261*/
			  [this._popr,2] /*262*/
			 ];
	    var arith=[		  
			 // arithmatic instrucions
			   [this._add,3], /*512*/
			    [this._sub,3], /*513*/
				[this._subi,3], /*514*/
				[this._addi,3] /*515*/
			 ];
			 // control instructions
		var ctrl=[
             [this._call,2], /*768*/
			 [this._ret,1],  /*769*/	
             [this._jmp,2] /*770*/			 
		 ];
		 // create instr map
		 // misc instr begin at 0
		 for(var i=0;i<misc.length;i++){
		     this._instrMap[i]=misc[i];
		 }
		 // data_mov instr begin at 256
		 for(var i=0;i<data_mov.length;i++){
		     this._instrMap[i+256]=data_mov[i];
		 }
		 // arith instr begin at 512
		 for(var i=0;i<arith.length;i++){
		     this._instrMap[i+512]=arith[i];
		 }
		 // ctrl instr begin at 768
		 for(var i=0;i<ctrl.length;i++){
		     this._instrMap[768+i]=ctrl[i];
		 }
		 this._regNames=[
		     "$a","$b","$c","$sp","$fp","$t0","$t1","$t2","$t3","$t4",
			 "$t7","$t8","$t9","$t10","$t11","$t12","$t13","$t14","$t15","$t16",
			 "$t17","$t18","$t19","$20","$t21","$t22","$t23","$t24","$t25","$ra",
			 "$flags","$pc"
		 ];//reg names;
		 this._regs={};
		 for(var i=0;i<this._regNames.length;i++) this._regs[this._regNames[i]]=i;
		 this._regMem=new Array(32);// each array Item represents a 32 bit register;
		 this.reset();
	 },
	 reset:function(){
	     for(var i=0;i<this._regMem.length;i++){
		     this._regMem[i]=0;
		 }
		 // initialize stack pointer to end of memory
		 this._regMem[this._regs['$sp']]=this._mem.length-1; 
	 },
	 getInstrSize:function(instr){
	     return this._instrMap[instr][1];
	 },
	 start:function(){
	    this._next_instr();
	 },
	 writeMem:function(addr,word){
	     this._mem[addr]=word;
	 },
	 readMem:function(addr){
	     return this._mem[addr];
	 },
	_regVal:function(idx){
	    return this._regMem[idx];
	},
	_setReg:function(idx,val){
	    return this._regMem[idx]=val;
	},
	_incPC:function(v){
	    this._regMem[this._regs['$pc']]+=(v?v:1);
	},
    _pc:function(){
	    return this._regVal(this._regs['$pc']);
	},
    _next_instr:function(){
        this._decodeInstr(this._readInstr()).call(this);
		
    },
	_readInstr:function(){
	    return this._mem[this._pc()];
	},
	_decodeInstr:function(instr){
	    console.log("decodding "+instr);
		console.log(this._regMem);
	    return this._instrMap[instr][0];
	},
	// methods defining instructions
	_nop:function(){
	    this._incPC();
		this._next_instr();
	},
	_mv:function(){
	    var pc=this._regMem[this._regs['$pc']];
	    this._mem[this._mem[pc+1]]=this._mem[this._mem[pc+2]];
	    this._incPC(3);
		this._next_instr();
	},
	_ld:function(){
	    var pc=this._regMem[this._regs['$pc']];
		this._regMem[this._mem[pc+1]]=this._mem[this._mem[pc+2]];
	    this._incPC(3);
		this._next_instr();
	},
	_ldi:function(){
	    var pc=this._regMem[this._regs['$pc']];
		this._regMem[this._mem[pc+1]]=this._mem[pc+2];
	    this._incPC(3);
		this._next_instr();
	},
	_st:function(){
	    var pc=this._regMem[this._regs['$pc']];
		this._mem[this._mem[pc+1]]=this._regMem[this._mem[pc+2]];
	    this._incPC(3);
		this._next_instr();
	},
	_sti:function(){
	    var pc=this._regMem[this._regs['$pc']];
		this._mem[this._mem[pc+1]]=this._mem[pc+2];
	    this._incPC(3);
		this._next_instr();
	},
	_add:function(){
	    var pc=this._regMem[this._regs['$pc']];
		this._regMem[this._mem[pc+1]]+=this._regMem[this._mem[pc+2]];
	    this._incPC(3);
	},
	_sub:function(){
	    var pc=this._regMem[this._regs['$pc']];
		this._regMem[this._mem[pc+1]]-=this._regMem[this._mem[pc+2]];
	    this._incPC(3);
		this._next_instr();
	},
	_subi:function(){
	     var pc=this._regMem[this._regs['$pc']];
		this._regMem[this._mem[pc+1]]-=this._mem[pc+2];
	    this._incPC(3);
		this._next_instr();
	},
	_addi:function(){
	    var pc=this._regMem[this._regs['$pc']];
		this._regMem[this._mem[pc+1]]+=this._mem[pc+2];
	    this._incPC(3);
		this._next_instr();
	},
	_call:function(){
	    var pc=this._regMem[this._regs['$pc']];
		var addr=this._mem[pc+1];
		this._regMem[this._regs['$ra']]=pc+2; // store return address
		this._regMem[this._regs['$pc']]=addr;
		this._next_instr();
	},
	_jmp:function(){
	    var pc=this._regMem[this._regs['$pc']];
		var addr=this._mem[pc+1];
		this._regMem[this._regs['$pc']]=addr;
		this._next_instr();
	},
	_ret:function(){
	     // load return address in program counter
	    this._regMem[this._regs['$pc']]=this._regMem[this._regs['$ra']];
		this._next_instr();
	},
	_pushr:function(){
	     var pc=this._regMem[this._regs['$pc']];
		 this._mem[this._regMem[this._regs['$sp']]]=this._regMem[this._mem[pc+1]];
		 this._regMem[this._regs['$sp']]--;
		 this._incPC(2);
		 this._next_instr();
	},
	_popr:function(){
	     var pc=this._regMem[this._regs['$pc']];
		 this._regMem[this._regs['$sp']]++;
		 this._regMem[this._mem[pc+1]]=this._mem[this._regMem[this._regs['$sp']]];
		 this._incPC(2);
		 this._next_instr();
	},
	_halt:function(){
	   this._incPC();
	},
	_syscall:function(){
	    var calltype=this._regMem[this._regs['$a']];
		var baddr = this._regMem[this._regs['$b']];
		var numBytes = this._regMem[this._regs['$c']];
		switch(calltype){
		   case 0:
		      // here we will write to output stream;
			  for(var i=0;i<numBytes;i++){
			      this._outStream.write(this._mem[baddr+i]&0xFF);
			  }
		   break;
		   case 1:
		      // here we will read from input stream;
			  for(var i=0;i<numBytes;i++){
			      this._mem[baddr+i] = this._inStream.read();
			  }
		   break;
		   default:
		     throw new Error("Undefined Syscall");
		   break;
		}
	    this._incPC();
		this._next_instr();
	}
	
	
};