/*
  Thomas Pham
  CruzID: 1593385
  pa1
*/
public class List {

  private class Node {
    // Fields..
    Object data;
    Node next;
    Node prev;

    // Constructor
    Node(Object data) {
      this.data = data;
      this.next = null;
      this.prev = null;
    }

    // Overrides Object's toString() method.
    public String toString() {
      return String.valueOf(data);
    }
  }

  /* Start of List Class */

  private int length;
  private Node front;// this is the first node in the list
  private Node cursor;
  private int index;
  private Node back; // this is the last node in the list
  // Constructor

  List() { // Creates a new empty list.
    this.length = 0;
    this.cursor = null;
    this.index = -1;
    this.front = null;
    this.back = null;
  }

  // Access functions
  public int length() { // Returns the number of elements in this List.
    return length;
  }

  public int index() { // If cursor is defined, returns the index of the cursor element,
    // otherwise returns -1.
    if (cursor != null) {
      return index;
    } else
      return -1;
  }

  public Object front() { // Returns front element. Pre: length()>0
    return front.data;
  }

  public Object back() { // Returns back element. Pre: length()>0
    return back.data;
  }

  public Object get() { // Returns cursor element. Pre: length()>0, index()>=0
    return cursor.data;
  }

  public boolean equals(List L) { // Returns true if and only if this List and L are the same
    // integer sequence. The states of the cursors in the two Lists
    // are not used in determining equality.
    if (length != L.length) // if the lengths are not the same, they are not equal lists.
      return false;

    Node l1Node = front;
    Node l2Node = L.front;
    while (l1Node != null) { // walking through the entire list
      if (l1Node.data != l2Node.data)
        return false;
      else {
        l1Node = l1Node.next;
        l2Node = l2Node.next;
      }
    }
    return true;
  }

  // Manipulation procedures

  public void clear() { // Resets this List to its original empty state.
    length = 0;
    cursor = null;
    index = -1;
    front = null;
    back = null;
  }

  public void moveFront() { // If List is non-empty, places the cursor under the front element,
    // otherwise does nothing.
    if (length != 0) {
      cursor = front;
      index = 0;
    }
  }

  public void moveBack() { // If List is non-empty, places the cursor under the back element,
    // otherwise does nothing.
    if (length != 0) {
      cursor = back;
      index = length - 1;
    }
  }

  public void movePrev() { // If cursor is defined and not at front, moves cursor one step toward
    // front of this List, if cursor is defined and at front, cursor becomes
    // undefined, if cursor is undefined does nothing.
    if (cursor != null && index != 0) {
      cursor = cursor.prev;
      index--;
    } else if (cursor != null && index == 0) {
      cursor = null;
      index = -1;
    } else if (cursor == null) {
    } // do nothing
  }

  public void moveNext() { // If cursor is defined and not at back, moves cursor one step toward
    // back of this List, if cursor is defined and at back, cursor becomes
    // undefined, if cursor is undefined does nothing.
    if (cursor != null && index != length - 1) {
      cursor = cursor.next;
      index++;
    } else if (cursor != null && index == length - 1) {
      cursor = null;
      index = -1;
    } else if (cursor == null) {
    } // do nothing
  }

  public void prepend(Object data) { // Insert new element into this List. If List is non-empty,
    // insertion takes place before front element.
    Node newNode = new Node(data);
    newNode.prev = null;
    newNode.next = front;
    if (length > 0) // if not the only element in the list
      front.prev = newNode;
    front = newNode;
    length++;

    if (cursor != null) { // if the cursor is defined
      index++;
    }
    if (length == 1) { // if there is only one node in the list
      back = newNode;
    }

  }

  public void append(Object data) { // Insert new element into this List. If List is non-empty,
    // insertion takes place after back element.
    Node newNode = new Node(data);

    if (length == 0) { // if theres nothing in the list,
      prepend(data);
    } else {// adding to the front of the list
      back.next = newNode;
      newNode.prev = back;
      back = newNode;
      length++;
    }

  }

  public void insertBefore(Object data) { // Insert new element before cursor.
    // Pre: length()>0, index()>=0
    Node newNode = new Node(data);
    if (index == 0)
      prepend(data);
    else {
      newNode.prev = cursor.prev;
      newNode.next = cursor;
      cursor.prev.next = newNode;
      cursor.prev = newNode;
      index++;
      length++;
    }
  }

  public void insertAfter(Object data) { // Inserts new element after cursor.
    // Pre: length()>0, index()>=
    Node newNode = new Node(data);
    if (index == length - 1) { // if index is at the end of the list
      cursor.next = newNode;
      newNode.prev = cursor;
      back = newNode;
      length++;
    } else {
      cursor.next.prev = newNode;
      cursor.next = newNode;
      newNode.prev = cursor;
      length++;
    }
  }

  public void deleteFront() { // Deletes the front element. Pre: length()>0
    front = front.next;
    length--;

    if (index == 0) { // if cursor is at the beginning, set cursor to null
      index = -1;
      cursor = null;
    }
    if (cursor != null) {
      index--;
    }
  }

  public void deleteBack() { // Deletes the back element. Pre: length()>0
    back = back.prev;
    if (back != null) {
      back.next = null;
    } else { // only one element in the list
      front = null;
    }
    length--;
    if (index == length) { // if cursor is at the end, set cursor to null
      index = -1;
      cursor = null;
    }
  }

  public void delete() { // Deletes cursor element, making cursor undefined.
    // Pre: length()>0, index()>=0
    if (cursor == null) {
      // do nothing
    } else if (index == 0) {// cursor is the first element
      deleteFront();
    } else {
      Node prevNode = cursor.prev;
      prevNode.next = cursor.next;
      if (index == length - 1)// if cursor is last element;
        back = prevNode;
      cursor = null;
      length--;
      index = -1;
    }
  }

  public String toString() { // Overrides Object's toString method. Returns a String
    // representation of this List consisting of a space
    // separated sequence of integers, with front on left.
    if (length == 0)
      return new String("");

    Node currNode = front;
    String list = "";
    while (currNode != null) {
      list += currNode.data + " ";
      currNode = currNode.next;
    }
    list = list.substring(0, list.length() - 1);
    return list;
  }

}
