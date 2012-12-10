/**
 * runtime
 * defines start of program and calls main func
 * defines void __sscall_(type,VA_ARGS); function 
 */

var lib_runtime=(function(){
  var code=[
         {gdef:"__start"},
         768,{ref:"main"}, // call main
		 2, // halt		 
		 
		 // define __sscal_, this function accepts three params, 
		 // void __sscall_(int type,arg1,arg2,...) 
		 {gdef:"__sscall_"},
		 262,0, // pop type of syscall
		 262,1,// pop arg1
		 262,2,//pop arg2
		 261,29, // push $ra
		 1, // syscall
		 262,29, // pop $ra
		 769// ret
		 // __sscall_ definition ends here
      ];
  var data=[];
  return [code,data];
});