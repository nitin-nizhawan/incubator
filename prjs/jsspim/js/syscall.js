function do_syscall(){
    switch(R[REG_V0]){
	    case PRINT_INT_SYSCALL:
		   console.log(R[REG_A0]);
		    break;
	    case PRINT_S		
	}
}