var lib_hw=(function(ctx){
var code=new ctx().init().
         $({gdef:"print"},
		 70,0, // pop $a
		 70,1, //pop $b
		 70,2, //pop $c
		 69,29, //push $ra
		 1, // syscall
		 70,29, // pop into $ra
		 193, // ret
         {gdef:"main"}, 
		 69,29, // push $ra
		 //prepare call 
		 66,0,{dwd:12}, // ldi $a 21(length of string)
	     69,0, //push $a
		 66,0,{ref:"hwstr"}, // ldi $a hwstr
		 69,0, //push $a
		 66,0,{dwd:0}, // ldi $a 0
	     69,0, // push $a
		 66,6,{ref:"__sscall_"}, // call print
		 192,6,
		 70,0,  // pop all arguments to balance stack
		 70,0,
		 70,0,
		 // begin another call
		 66,0,{dwd:12}, // ldi $a 21(length of string)
	     69,0, //push $a
		 66,0,{ref:"awesm"}, // ldi $a hwstr
		 69,0, //push $a
		 66,0,{dwd:0}, // ldi $a 0
	     69,0, // push $a
		 66,6,{ref:"__sscall_"}, // call print
		 192,6,
		 70,0, // pop all arguments to balance stack
		 70,0,
		 70,0,
	     70,29, // pop into $ra
		 193); // ret
      
  var data=  new ctx().init().
             def("hwstr").
			 ascii("Hello Nitin\n").
			 def("awesm").
			 ascii("It's awesome");

  return [code,data];
});