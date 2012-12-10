/**
 * runtime
 * defines start of program and calls main func
 * defines void __sscall_(type,VA_ARGS); function 
 */

var lib_runtime=(function(){
  var IS = CPU.InstructionSet.NameToCode;
  var code=[
         {gdef:"__start"},
         IS.ldi_dw,0,{ref:"main"},0,0,0, // call main
		 IS.call,0, // call adresss in $a
		 IS.halt, // halt		 
		 
		 // define __sscal_, this function accepts three params, 
		 // void __sscall_(int type,arg1,arg2,...) 
		 {gdef:"__sscall_"},
		 IS.syscall, // syscall
		 IS.ret// ret
		 // __sscall_ definition ends here
      ];
  var data=[];
  return [code,data];
});