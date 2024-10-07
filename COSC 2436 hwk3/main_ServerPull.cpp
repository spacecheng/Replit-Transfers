#include <iostream>
#include <iomanip>
#include <fstream>
#include "ArgumentManager.h"
using namespace std;

void appendCreate(int*& array, int& size, int& capacity, int value){
  if(size == capacity){
    //cout << "expaned capacity\n";
    capacity = capacity * 2;
    int* temp = new int[capacity];
    for(int i = 0; i < size; i++){
      temp[i] = array[i];
    }
    delete[] array;
    array = temp;
  }
  //cout << "appendCreate set input array value to: " << value << endl;
  array[size] = value;
  size++;
}

void DrawBoard(int** board, int numRows, int numCols, ofstream& fout, bool isCout = false){
  if(isCout){
    for(int row = 0; row < numRows; row++){
      for(int col = 0; col < numCols; col++){
        cout << "+--";
      }
      cout << "+" << endl;
      for(int col = 0; col < numCols; col++){
        cout << "|";
        if(board[row][col] > 0){
          cout << setw(2) << board[row][col];
        }
        else if(board[row][col] == -1){              
          cout << "XX";
        }
        else {
          cout << " ";
        }
      }
      cout << "|" << endl;
    }
    for(int col = 0; col < numCols; col++){
      cout << "+--";
    }
    cout << "+" << endl;
  }
  else{
    for(int row = 0; row < numRows; row++){
      for(int col = 0; col < numCols; col++){
        fout << "+--";
      }
      fout << "+" << endl;
      for(int col = 0; col < numCols; col++){
        fout << "|";
        if(board[row][col] > 0){
          fout << setw(2) << board[row][col];
        }
        else if(board[row][col] == -1){              
          fout << "XX";
        }
        else {
          fout << " ";
        }
      }
      fout << "|" << endl;
    }
    for(int col = 0; col < numCols; col++){
      fout << "+--";
    }
    fout << "+" << endl;
  }
}

bool MarkBoard(int** board, int& startRow, int& startCol, int rowChange, int colChange, int maxRow, int maxCol, int& val){
  int rowNum = startRow + rowChange;
  int colNum = startCol + colChange;
  if(rowNum >= 0 && colNum >= 0 && rowNum < maxRow && colNum < maxCol){
    if(board[rowNum][colNum] == 0){
      //cout << "GOTO " << rowNum << " " << colNum << endl;
      board[rowNum][colNum] = val;
      startRow = rowNum;
      startCol = colNum;
      val++;
      return true;
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }
}

void Unmark(int** board, int& startRow, int& startCol, int rowChange, int colChange, int& val){
  board[startRow][startCol] = 0;
  startRow = startRow-rowChange;
  startCol = startCol-colChange;
  val--;
}

bool MoveAction(int** board, int*& optionNum, int& opNumSel, int& opNumSize, int& opNumCap, int numHoles, int& rowLocation, int& colLocation, int maxRow, int maxCol, int& val, int beginRow, int beginCol, bool& exit, bool start = false){
  if(exit){
    return false;
  }
  //DrawBoard(board, maxRow, maxCol);
  //int test;
  //cin >> test;
  /*for(int i = 0; i < opNumCap; i++){
    cout << optionNum[i] << " ";
  }
  cout << endl;*/
  //cout << "pos: " << rowLocation << " " << colLocation << endl;
  //cout << "OptionNum[" << opNumSel << "] is: " << optionNum[opNumSel] << endl;
  switch(optionNum[opNumSel]){
    case 1:{
      if(!MarkBoard(board, rowLocation, colLocation, -1, 2, maxRow, maxCol, val)){
        //cout << "OptionNum" << opNumSel << "'s option " << optionNum[opNumSel] << " failed" << endl;
        optionNum[opNumSel]++;
      }
      else{
        //cout << "OptionNum" << opNumSel << "'s option " << optionNum[opNumSel] << " passed" << endl;
        break;
      }
    }
    case 2:{
      if(!MarkBoard(board, rowLocation, colLocation, -2, 1, maxRow, maxCol, val)){
        //cout << "OptionNum" << opNumSel << "'s option " << optionNum[opNumSel] << " failed" << endl;
        optionNum[opNumSel]++;
      }
      else{
        //cout << "OptionNum" << opNumSel << "'s option " << optionNum[opNumSel] << " passed" << endl;
        break;
      }
    }
    case 3:{
      if(!MarkBoard(board, rowLocation, colLocation, -2, -1, maxRow, maxCol, val)){
        //cout << "OptionNum" << opNumSel << "'s option " << optionNum[opNumSel] << " failed" << endl;
        optionNum[opNumSel]++;
      }
      else{
        //cout << "OptionNum" << opNumSel << "'s option " << optionNum[opNumSel] << " passed" << endl;
        break;
      }
    }
    case 4:{
      if(!MarkBoard(board, rowLocation, colLocation, -1, -2, maxRow, maxCol, val)){
        //cout << "OptionNum" << opNumSel << "'s option " << optionNum[opNumSel] << " failed" << endl;
        optionNum[opNumSel]++;
      }
      else{
        //cout << "OptionNum" << opNumSel << "'s option " << optionNum[opNumSel] << " passed" << endl;
        break;
      }
    }
    case 5:{
      if(!MarkBoard(board, rowLocation, colLocation, 1, -2, maxRow, maxCol, val)){
        //cout << "OptionNum" << opNumSel << "'s option " << optionNum[opNumSel] << " failed" << endl;
        optionNum[opNumSel]++;
      }
      else{
        //cout << "OptionNum" << opNumSel << "'s option " << optionNum[opNumSel] << " passed" << endl;
        break;
      }
    }
    case 6:{
      if(!MarkBoard(board, rowLocation, colLocation, 2, -1, maxRow, maxCol, val)){
        //cout << "OptionNum" << opNumSel << "'s option " << optionNum[opNumSel] << " failed" << endl;
        optionNum[opNumSel]++;
      }
      else{
        //cout << "OptionNum" << opNumSel << "'s option " << optionNum[opNumSel] << " passed" << endl;
        break;
      }
    }
    case 7:{
      if(!MarkBoard(board, rowLocation, colLocation, 2, 1, maxRow, maxCol, val)){
        //cout << "OptionNum" << opNumSel << "'s option " << optionNum[opNumSel] << " failed" << endl;
        optionNum[opNumSel]++;
      }
      else{
        //cout << "OptionNum" << opNumSel << "'s option " << optionNum[opNumSel] << " passed" << endl;
        break;
      }
    }
    case 8:{
      if(!MarkBoard(board, rowLocation, colLocation, 1, 2, maxRow, maxCol, val)){
        //cout << "OptionNum" << opNumSel << "'s option " << optionNum[opNumSel] << " failed" << endl;
        optionNum[opNumSel]++;
      }
      else{
        //cout << "OptionNum" << opNumSel << "'s option " << optionNum[opNumSel] << " passed" << endl;
        break;
      }
    }
  }
  if(opNumSel <= 0 && !start){
    //cout << "ran";
    exit = true;
    return false;
  }
  if(optionNum[opNumSel] < 9){
    appendCreate(optionNum, opNumSize, opNumCap, 1);
    opNumSel = opNumSize-1;
    MoveAction(board, optionNum, opNumSel, opNumSize, opNumCap, numHoles, rowLocation, colLocation, maxRow, maxCol, val, beginRow, beginCol, exit);
  }
  else{
    if(opNumSize + numHoles == maxRow*maxCol){
      if((beginRow + 2 == rowLocation && beginCol + 1 == colLocation)
      || (beginRow - 1 == rowLocation && beginCol + 2 == colLocation)
      || (beginRow - 2 == rowLocation && beginCol + 1 == colLocation)
      || (beginRow - 2 == rowLocation && beginCol - 1 == colLocation)
      || (beginRow - 1 == rowLocation && beginCol - 2 == colLocation)
      || (beginRow + 1 == rowLocation && beginCol - 2 == colLocation)
      || (beginRow + 2 == rowLocation && beginCol - 1 == colLocation)
      || (beginRow + 1 == rowLocation && beginCol + 2 == colLocation)){
        return true;
      }
    }
      optionNum[opNumSel] = 0;
      opNumSize--;
      opNumSel = opNumSize-1;
      int unmarkVal = 0;
      //Swu]itch is for inverse actions
      switch(optionNum[opNumSel]){
        case 1:{
          Unmark(board, rowLocation, colLocation, -1, 2, val);
          break;
        }
        case 2:{
          Unmark(board, rowLocation, colLocation, -2, 1, val);
          break;
        }
        case 3:{
          Unmark(board, rowLocation, colLocation, -2, -1, val);
          break;
        }
        case 4:{
          Unmark(board, rowLocation, colLocation, -1, -2, val);
          break;
        }
        case 5:{
          Unmark(board, rowLocation, colLocation, 1, -2, val);
          break;
        }
        case 6:{
          Unmark(board, rowLocation, colLocation, 2, -1, val);
          break;
        }
        case 7:{
          Unmark(board, rowLocation, colLocation, 2, 1, val);
          break;
        }
        case 8:{
          Unmark(board, rowLocation, colLocation, 1, 2, val);
          break;
        }
      }
      //cout << "New optionum set is: " << opNumSel << endl;
      optionNum[opNumSel]++;
      MoveAction(board, optionNum, opNumSel, opNumSize, opNumCap, numHoles, rowLocation, colLocation, maxRow, maxCol, val, beginRow, beginCol, exit);
      return false;
  }
  return false;
}

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  //ifstream fin(am.get("input"));
  //ofstream fout(am.get("output"));
  //get inputs{
  int numRows, numCols, startRow, startCol, numHoles;
  int** holeLocations;
  int inputNum = 3; // change this val per file
  bool exitStatus = false;
  ifstream fin("input" + to_string(inputNum) + ".txt");
  ofstream fout("output"+ to_string(inputNum) + ".txt");
  fin >> numRows;
  fin >> numCols;
  fin >> startRow;
  fin >> startCol;
  fin >> numHoles;
  //cout << startRow << " "<< startCol << endl;
  //get holes{
  //The 1st val in hole location is the row num and the second is the col num
  holeLocations = new int*[numHoles];
  for(int i = 0; i < numHoles; i++){
    holeLocations[i] = new int[2];
    fin >> holeLocations[i][0];
    fin >> holeLocations[i][1];
  }
  /*for(int i = 0; i < numHoles; i++){
    cout << "Hole " << i << ": ";
    for(int j = 0; j < 2; j++){
      cout << holeLocations[i][j];
      cout << " ";
    }
    cout << endl;
  }*/
  //}
  //}
  //create board{
  int** board = new int*[numRows];
  for(int row = 0; row < numRows; row++) {
    board[row] = new int[numCols];
    for(int col = 0; col < numCols; col++){
      board[row][col] = 0;
    }
  }
  //fill holes{
  for(int i = 0; i < numHoles; i++){
    int holeRow = holeLocations[i][0];
    int holeCol = holeLocations[i][1];
    board[holeRow][holeCol] = -1;
  }
  //}
  //}

  int count = 1;
  int optionNumSelector = 0;
  int optionNumSize = 1;
  int optionNumCapacity = 8;
  int* optionNum = new int[optionNumCapacity];
  optionNum[0] = 1;
  //cout << "Game start " << endl;
  //cout << startRow << " "<< startCol << endl;
  MarkBoard(board, startRow, startCol, 0, 0, numRows, numCols, count);
  //cout << startRow << " "<< startCol << endl;
  MoveAction(board, optionNum, optionNumSelector, optionNumSize, optionNumCapacity, numHoles, startRow, startCol, numRows, numCols, count, startRow, startCol, exitStatus, true);
  cout << endl << "OptionNum: ";
  for(int i = 0; i < optionNumCapacity; i++){
    cout << optionNum[i] << " ";
  }
  cout << endl;
  if(optionNum[1] == 0){
    fout << "A closed tour does not exist!" << endl;
    cout << "A closed tour does not exist!" << endl;
  }
  else{
    fout << "A closed tour exists!\n";
    cout << "A closed tour exists!\n";
    DrawBoard(board, numRows, numCols, fout, true);
    DrawBoard(board, numRows, numCols, fout);
  }
  return 0;
}

