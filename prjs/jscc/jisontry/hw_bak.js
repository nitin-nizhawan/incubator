var lib_hw=(function(ctx){
 var code=[
         {gdef:"print"},
		 262,0, // pop $a
		 262,1, //pop $b
		 262,2, //pop $c
		 261,29, //push $ra
		 1, // syscall
		 262,29, // pop into $ra
		 769, // ret
         {gdef:"main"}, 
		 261,29, // push $ra
		 //prepare call 
		 258,0,12, // ldi $a 21(length of string)
		 261,0, //push $a
		 258,0,{ref:"hwstr"}, // ldi $a hwstr
		 261,0, //push $a
		 258,0,0, // ldi $a 0
		 261,0, // push $a
		 768,{ref:"__sscall_"}, // call print
		 262,29, // pop into $ra
		 769 // ret
      ];
  var data= [{def:"hwstr"}].
            concat(ctx.ascii("Hello Nitin\n")).
			concat([{def:"awesm"}]).
			concat(ctx.ascii("It's awesome"));
  return [code,data];
});