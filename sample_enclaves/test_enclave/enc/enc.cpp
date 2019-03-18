

void exec(){

	  evm::SimpleGlobalState gs;

	const evm::AccountState contract = gs.create(to, 0, code);
	evm::Processor p(gs);

}