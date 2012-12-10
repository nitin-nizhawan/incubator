var Machine=(function(){
    var pc=0;
	var mem=new Array(64*1024);
	var R = new Array(32);
	var Labels={};
	var instrName=[];
	var instrFun=["ADDU"];
	return {
	    subu:function(reg1,reg2,imm){
		    R[reg1]=R[reg2]-imm;
			pc+=3;
		},
		syscall:function(reg1,reg2){
		    if(R[reg1]==4){
			    //console.log(readStr(R[reg2]));
			}
		},
		sw:function(){
		},
		li:function(){
		},
		jr:function(){
		},
		addiu:function(){
		},
		la:function(){
		},
		jal:function(){
		},
		label:function(str){
		     return function(){
			      
			 };
		},
	}
});

function Loader(){
}
Loader.prototype={
    
};
var source = 'def(label,"mstr",
    asciiz("Hello World\n"),
	globl("main"),
	label("printf"),
	subu,$sp,$sp,32,
	sw,$ra,20,$sp,
	sw,$fp,16,$sp,
	li,$v0,4,
	syscall,
	lw,$ra,20,$sp,
	lw,$fp,16,$sp,
	addiu,$sp,$sp,32,
	jr,$ra,
    subu,$sp,$sp,32,
    sw,$ra,20,$sp,
    sw,$fp,16,$sp,
	addiu,$fp,$sp,28,
    la,$a0,addof("mstr"),
	jal,addof("printf"),
	lw,$ra,20,$sp,
	addiu,$sp,$sp,32,
	jr,$ra);';