/*
  Thomas Pham
  CruzID: 1593385
  pa1
*/
import java.io.*;
import java.util.*;

class Lex{
	public static void main(String[] args) throws IOException{
      Scanner in = null;
      PrintWriter out = null;
      String line = null;

      if(args.length != 2){
       System.err.println("Usage: FileIO infile outfile");
       System.exit(1);
      }

      in = new Scanner(new File(args[0]));
      out = new PrintWriter(new File(args[1]));

      String lines[] = new String[getLineCount(in)];
      List list = new List();

      in = new Scanner(new File(args[0])); //resetting scanner

      int currLine = 0;

      //Populating array with lines
      while(in.hasNextLine()){
        lines[currLine] = in.nextLine();
        currLine++;
      }
      //HashTable <Integer, Boolean> ht = new HashTable<Integer, Boolean>();
      for(int i = 0; i < lines.length; i++){
        int smallestIndex = 0;
        //while(ht.get(smallestIndex) == null)
          //smallestIndex++;
        while(isInList(list,smallestIndex)) { //find the next element that is not in the list
          smallestIndex++;
        }
        for(int j = smallestIndex; j < lines.length; j++) {
          //making sure we are getteing the index that is not in the list yet
          //if(lines[smallestIndex].compareTo(lines[j]) > 0 && ht.get(j) != null)
          if(lines[smallestIndex].compareTo(lines[j]) > 0 && !isInList(list,j)) {
           smallestIndex = j;
          }
        }
          list.append(smallestIndex); //adding the index to the list
          //ht.put(smallestIndex, true);
        }
      writeFile(list,lines,out);
    }

    //Writes indiceis of the array to file in Lexographical order.
    public static void writeFile(List list, String[] lines, PrintWriter out){
      String[] token = null;
      String output = list.toString();
      list.moveFront();
      token = output.split("\\s+"); //splitting list by spaces

      for(int i = 0; i < token.length; i++){
        out.println(lines[Integer.parseInt(token[i])]);
        out.flush();
      }
    }

    //Checks to see if i is already in a list.
    //This could be made more efficient by implementing a HashTable using the java
    //library, but I was unclear if I was able to use it or not.
    public static boolean isInList(List list, int i){
      list.moveFront();
      while(list.index() != -1){ //going through list to make sure i is not already used
        if(list.get() == i)
          return true;
        list.moveNext();
      }
      return false;
    }
    //count the amount of lines in the file
    public static int getLineCount(Scanner in){
      int lineCount = 0;
      String line = "";
      while(in.hasNextLine()){
        line = in.nextLine();
        lineCount++;
      }
      return lineCount;
    }
}
