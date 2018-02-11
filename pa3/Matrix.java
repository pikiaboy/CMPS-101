class Matrix {

  // Entry Class
  private class Entry {
    int col;
    double val;

    Entry(int col, double val) {
      this.col = col;
      this.val = val;
    }

    public boolean equals(Object x) {
      Entry temp = (Entry) x;
      if (temp.col == col && temp.val == val)
        return true;
      else
        return false;
    }

    public String toString() {
      String ret = "(" + col + ", " + val + ")";
      return ret;
    }

  }
  // End of Entry Class

  int size;
  int NNZ;
  List[] row; // NOTE: 0-th index is not used. Everything is 1 based.

  Matrix(int n) {
    row = new List[n];
    size = n;
  }

  // Acessor functions
  public int getSize() {
    return size;
  }

  public int getNNZ() {
    return NNZ;
  }

  // Maipulation functions

  void makeZero() {
    for (int i = 0; i < size; i++) {
      row[i] = null;
    }
  }

  Matrix copy() {
    Matrix newMatrix = new Matrix(size);

    for (int i = 0; i < size; i++) {// copying each index
      newMatrix.row[i] = this.row[i];
    }

    return newMatrix;
  }

  public void changeEntry(int i, int j, double x) {
    // Changes i-th row and j-th col to x
    Entry E = new Entry(j, x);
    Entry temp;

    if (row[i] == null) { // if list has not been made yet
      row[i] = new List();
    }

    row[i].moveFront();
    if (row[i].index() == -1) {
      row[i].append(E); // if list has nothing in it, append data.
      return;
    }

    while (row[i].index() != -1) {// if index == -1, then Aij is 0
      if (((Entry) row[i].get()).col > j) {// if we went past the col number
        row[i].insertBefore(E);
        break;
      } else if (((Entry) row[i].get()).col == j) {// if col is equal to the col we want
        if (x == 0) {// if x is 0, delete the node
          row[i].delete();
          break;
        } else { // else, change val to new value.
          ((Entry) row[i].get()).val = x;
          break;
        }
      }
    }

    if (row[i].index() == -1 && x != 0) {// if Aij == 0 and x contians a value
      // add new node to list
      row[i].append(E);
    }

  }

  public Matrix scalarMult(double x) {
    Matrix newMatrix = this.copy();
    for (int i = 0; i < size; i++) {// go through every row
      if (row[i] == null)
        continue;
      newMatrix.row[i].moveFront();
      while (row[i].index() != -1) {
        ((Entry) newMatrix.row[i].get()).val *= x;
        newMatrix.row[i].moveNext();
      }
    }
    return newMatrix;
  }

  public String toString() {
    String ret = "";

    for (int i = 0; i < size; i++) {
      if (row[i] == null)// if list doesn't exit, continue with the loop
        continue;

      ret += i + ": ";
      row[i].moveFront();
      while (row[i].index() != -1) {// keep going until end of list
        ret += ((Entry)row[i].get()).toString() + " ";
        row[i].moveNext();
      }
      ret += "\n";
    }

    return ret;
  }

}
