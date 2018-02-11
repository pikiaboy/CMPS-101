class Test {
  public static void main(String[] args) {
    List l = new List();

    Matrix m = new Matrix(10);

    m.changeEntry(5, 5, 10);

    m.changeEntry(5, 5, 3);

    m.changeEntry(5, 4, 1);

    m.changeEntry(1, 5, 10);

    m.scalarMult(2);

  }
}
