
void animation(string animation){
	int counter = 0 ;
	while(animation[counter] != '\0'){
		cout << animation[counter];
		Sleep(90);
		counter++;
	}

}
void m(int n=10){
	for(int i=0;i<=n;i++){
		cout << " ";
	}
}
void blankline(int n=1){
		for(int i=0;i<=n;i++){
		cout << endl;
	}
}
void line(){
	for(int i =0;i<=77;i++){cout << '-';}cout << endl;
}


