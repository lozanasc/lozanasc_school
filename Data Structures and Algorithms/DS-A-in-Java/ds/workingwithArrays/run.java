class run {
	public static void main(String[] args) {
		arrays testArray = new arrays(3);
		testArray.insert(5);
		testArray.insert(4);
		testArray.insert(3);
		testArray.insert(2);
		testArray.insert(1);
		System.out.print(testArray.indexOf(1)+"\n");
		testArray.print();
	}
}