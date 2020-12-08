// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author1:  Hussien Ashraf Feteiha 20170093 G:4
// Author2:  Hussien Tarek Ismail 20170094 G:4
// Author3:  Peter Malak Mikhael 20170079 G:3
// Date:    10/4/2018

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char anotherimage[SIZE][SIZE];

void loadImage ();
void saveImage ();
void menues();

void bandw ();
void flip ();
void detect();
void mirror();

void invert ();
void rotate () ;
void enlarge () ;
void shuffle () ;

void merging();
void brightness ();
void blur();
void shrink();


int main()
{
  char choice;
  cout << "Ahlan ya user ya Habibi :)" <<endl;
  loadImage();
  while (true){
  menues();
  cin >> choice;
  if (choice == '0'){
    cout << "BYE!" <<endl;
    return 0;
  }
  else if (choice =='L' || choice == 'l'){
    loadImage();
  }
  else if (choice == '1'){
  bandw();
  }
  else if (choice == '2')
  {
      invert() ;
  }
  else if (choice == '3'){
    merging();
  }
  else if (choice == '4'){
   flip();
  }
  else if (choice == '5'){
    brightness();
  }
  else if (choice == '6')
  {
    rotate() ;
  }
  else if (choice == '7'){
   detect();
  }
  else if (choice == '8')
  {
    enlarge() ;
  }
  else if (choice == '9'){
    shrink();
  }
  else if (choice == 'a' || choice == 'A'){
    mirror();
  }
  else if (choice == 'b' || choice == 'B')
  {
    shuffle() ;
  }
  else if (choice == 'c' || choice == 'C'){
    blur();
  }
  else if (choice=='s' || choice == 'S'){
  saveImage();
  }
  else {
    cout << "Wrong Input!" << endl;
  }
  }
  return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

//_________________________________________
void menues(){
cout << endl << "Please select filter to apply or 0 to exit:" <<endl;
cout << "1- Black & White filter." <<endl;
cout << "2- Invert Filter." <<endl;
cout << "3- Merge Images" << endl;
cout << "4- Flip Image." <<endl;
cout << "5-Darken and Lighten Image" << endl ;
cout << "6- Rotate Image." <<endl;
cout << "7- Detect Image Edges." <<endl;
cout << "8- Enlarge Image." <<endl;
cout << "9-Shrink Image" << endl;
cout << "A- Mirror 1/2 Image." <<endl;
cout << "B- Shuffle Image." <<endl;
cout << "C- Blur." << endl ;
cout << "S- Save the Image to a file." <<endl;
cout << "L- Load Image." <<endl;
cout << "0- Exit." <<endl;
}

void bandw() {
  int avg=0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        //black and white filter
        avg= avg + image[i][j];

    }
  }
  avg =avg / (SIZE * SIZE);
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        if (image[i][j]>= avg){
            image[i][j]= 255;
        }
        else{
            image[i][j] = 0;
        }

    }
  }
}
void flip() {
  char c;
  unsigned char tempo[SIZE][SIZE];
  cout << "Flip (h)orizontally or (v)ertically?" <<endl;
  cin >> c;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
       tempo[i][j]=image[i][j];

    }
  }
    if (c=='h' || c=='H'){
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j]=tempo[i][(SIZE-1)-j];

    }
  }
    }
  else if (c=='v' || c=='V'){
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j]=tempo[(SIZE-1)-i][j];

    }
  }
  }
  else{
    cout <<"Error, Wrong Choice!" <<endl;
  }
}
void detect() {
    unsigned char tempo[SIZE][SIZE];
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
            if (abs(image[i][j]-image[i][j+1])>=35 || abs(image[i][j] - image[i+1][j]) >=35){
                image [i][j] = 0;
            }
            else {
                image[i][j]=255;
            }
    }
  }}
void mirror(){
  cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?" <<endl;
  char letter;
  cin >> letter;
  if (letter != 'l' && letter != 'L' && letter != 'r' && letter != 'R' && letter != 'u' && letter !='U' && letter != 'd' && letter !='D')
  {
      cout << "Wrong Input" <<endl;
      return;
  }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
      if (letter == 'u' || letter == 'U'){
      image[SIZE-i][j]=image [i][j];
      }
      else if (letter == 'd' || letter == 'D'){
        image[i][j]=image[SIZE-i][j];
      }
      else if (letter == 'r' || letter == 'R'){
        image[i][j]=image[i][SIZE-j];
      }
      else if (letter == 'l' || letter == 'L'){
        image[i][SIZE-j]=image[i][j];
      }
    }
  }
}


void invert()
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j< SIZE; j++)
    {

        image[i][j] = ~image[i][j] ;


    }
  }
}
void rotate()
{
    unsigned char temp[SIZE][SIZE] ;
    string degree ;
    while (true)
    {
        cout << "Rotate (90), (180) or (270) degrees? : " ;
        cin >> degree ;
        cout << "\n" ;
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j< SIZE; j++)
                temp[i][j] = image[i][j] ;
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j< SIZE; j++)
                image[i][j] = temp[j][SIZE-1-i] ;
        if(degree == "90")
            return ;
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j< SIZE; j++)
                temp[i][j] = image[i][j] ;
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j< SIZE; j++)
                image[i][j] = temp[j][SIZE-1-i] ;
        if(degree == "180")
            return ;
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j< SIZE; j++)
                temp[i][j] = image[i][j] ;
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j< SIZE; j++)
                image[i][j] = temp[j][SIZE-1-i] ;
        if(degree == "270")
            return ;
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j< SIZE; j++)
                temp[i][j] = image[i][j] ;
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j< SIZE; j++)
                image[i][j] = temp[j][SIZE-1-i] ;
        cout << "wrong choice !!" << endl << endl ;
    }
}
void enlarge()
{
    string quarter ;
    unsigned char temp[SIZE][SIZE] ;
    while (true)
    {
        cout << "Which quarter to enlarge 1, 2, 3 or 4? : " ;
        cin >> quarter ;
        if(quarter== "1")
        {
            for(int i = 0 ; i < SIZE/2 ; i++)
                for (int j = 0 ;j < SIZE/2 ; j++)
                    temp[i][j] = image[i][j] ;
            break ;
        }
        else if(quarter== "2")
        {
            for(int i = 0 ; i < SIZE/2 ; i++)
                for (int j = 0 ;j < SIZE/2 ; j++)
                    temp[i][j] = image[i][j + SIZE/2] ;
            break ;
        }
        else if(quarter== "3")
        {
             for(int i = 0 ; i < SIZE/2 ; i++)
                for (int j = 0 ;j < SIZE/2 ; j++)
                    temp[i][j] = image[i + SIZE/2][j]  ;
            break ;
        }
        else if(quarter== "4")
        {
            for(int i = 0 ; i < SIZE/2 ; i++)
                for (int j = 0 ;j < SIZE/2 ; j++)
                    temp[i][j] = image[i + SIZE/2][j + SIZE/2]  ;
            break ;
        }
        else
            cout << "wrong choice !!" << endl << endl ;
    }

    for (int i = 0 , ii = 0 ; i < SIZE ; ii++ , i += 2)
    {
        for (int j = 0 , jj = 0 ; j < SIZE ; jj++ , j += 2)
        {
            image[i][j] = temp[ii][jj] ;
            image[i+1][j] = temp[ii][jj] ;
            image[i][j+1] = temp[ii][jj] ;
            image[i+1][j+1] = temp[ii][jj] ;
        }
    }
}
void shuffle()
{
    int quarter ;
    unsigned char temp1[SIZE/2][SIZE/2],temp2[SIZE/2][SIZE/2],temp3[SIZE/2][SIZE/2],temp4[SIZE/2][SIZE/2] ;
    for(int i = 0 ; i < SIZE/2 ; i++)
        for(int j = 0 ; j < SIZE/2 ; j++)
            temp1[i][j] = image[i][j] ;
    for(int i = 0 ; i < SIZE/2 ; i++)
        for(int j = 0 ; j < SIZE/2 ; j++)
            temp2[i][j] = image[i][j + SIZE/2] ;
    for(int i = 0 ; i < SIZE/2 ; i++)
        for(int j = 0 ; j < SIZE/2 ; j++)
            temp3[i][j] = image[i + SIZE/2][j] ;
    for(int i = 0 ; i < SIZE/2 ; i++)
        for(int j = 0 ; j < SIZE/2 ; j++)
            temp4[i][j] = image[i + SIZE/2][j + SIZE/2] ;

    int order = 1 ;
    cout << "New order of quarters ? : " ;
    while(order <= 4)
    {
        cin >> quarter ;
        if(quarter == 1)
        {
            if(order == 1)
            {
                for(int i = 0 ; i < SIZE/2 ; i++)
                    for(int j = 0 ; j < SIZE/2 ; j++)
                        image[i][j] = temp1[i][j] ;

            }
            else if(order == 2)
            {
                for(int i = 0 ; i < SIZE/2 ; i++)
                    for(int j = SIZE/2 ; j < SIZE ; j++)
                        image[i][j] = temp1[i][j - SIZE/2] ;

            }
            else if(order == 3)
            {
                for(int i = SIZE/2 ; i < SIZE ; i++)
                    for(int j = 0 ; j < SIZE/2 ; j++)
                        image[i][j] = temp1[i - SIZE/2][j] ;

            }
            else if(order == 4)
            {
                for(int i = SIZE/2  ; i < SIZE ; i++)
                    for(int j = SIZE/2 ; j < SIZE ; j++)
                        image[i][j] = temp1[i - SIZE/2][j - SIZE/2] ;

            }

        }
        else if(quarter == 2)
        {
            if(order == 1)
            {
                for(int i = 0 ; i < SIZE/2 ; i++)
                    for(int j = 0 ; j < SIZE/2 ; j++)
                        image[i][j] = temp2[i][j] ;

            }
            else if(order == 2)
            {
                for(int i = 0 ; i < SIZE/2 ; i++)
                    for(int j = SIZE/2 ; j < SIZE ; j++)
                        image[i][j] = temp2[i][j - SIZE/2] ;

            }
            else if(order == 3)
            {
                for(int i = SIZE/2 ; i < SIZE ; i++)
                    for(int j = 0 ; j < SIZE/2 ; j++)
                        image[i][j] = temp2[i - SIZE/2][j] ;

            }
            else if(order == 4)
            {
                for(int i = SIZE/2 ; i < SIZE ; i++)
                    for(int j = SIZE/2 ; j < SIZE ; j++)
                        image[i][j] = temp2[i - SIZE/2][j - SIZE/2] ;

            }

        }
        else if(quarter == 3)
        {
            if(order == 1)
            {
                for(int i = 0 ; i < SIZE/2 ; i++)
                    for(int j = 0 ; j < SIZE/2 ; j++)
                        image[i][j] = temp3[i][j] ;

            }
            else if(order == 2)
            {
                for(int i = 0 ; i < SIZE/2 ; i++)
                    for(int j = SIZE/2 ; j < SIZE ; j++)
                        image[i][j] = temp3[i][j - SIZE/2] ;

            }
            else if(order == 3)
            {
                for(int i = SIZE/2 + 1 ; i < SIZE ; i++)
                    for(int j = 0 ; j < SIZE/2 ; j++)
                        image[i][j] = temp3[i - SIZE/2][j] ;

            }
            else if(order == 4)
            {
                for(int i = SIZE/2 ; i < SIZE ; i++)
                    for(int j = SIZE/2 ; j < SIZE ; j++)
                        image[i][j] = temp3[i - SIZE/2][j - SIZE/2] ;

            }

        }
        else if(quarter == 4)
        {
            if(order == 1)
            {
                for(int i = 0 ; i < SIZE/2 ; i++)
                    for(int j = 0 ; j < SIZE/2 ; j++)
                        image[i][j] = temp4[i][j] ;

            }
            else if(order == 2)
            {
                for(int i = 0 ; i < SIZE/2 ; i++)
                    for(int j = SIZE/2 ; j < SIZE ; j++)
                        image[i][j] = temp4[i][j - SIZE/2] ;

            }
            else if(order == 3)
            {
                for(int i = SIZE/2 ; i < SIZE ; i++)
                    for(int j = 0 ; j < SIZE/2 ; j++)
                        image[i][j] = temp4[i - SIZE/2][j] ;

            }
            else if(order == 4)
            {
                for(int i = SIZE/2 ; i < SIZE ; i++)
                    for(int j = SIZE/2 ; j < SIZE ; j++)
                        image[i][j] = temp4[i - SIZE/2][j - SIZE/2] ;

            }

        }
        else
        {
            cout << " wrong choice !!" << endl << endl ;
            cout << "New order of quarters ? : " ;
            continue ;
        }
        order++ ;

    }
}


void brightness() {
  char x ;
  cout << "(D)arken and (L)ighten Image" << endl ;
  cin >> x ;
  if ( x == 'd' || x == 'D'){
    for (int i = 0; i < SIZE; i++) {
       for (int j = 0; j < SIZE; j++) {

        image[i][j] = (image[i][j])/2;

    }
   }
  }
  if ( x == 'l' || x == 'L'){
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {


        image[i][j] = ((image[i][j])+255) / 2 ;
        if ((((image[i][j])+255) / 2) > 255){
            image[i][j] = 255 ;
        }

    }
   }
  }

}
void merging(){
   char FileName[100];

   cout << "Enter the source image file name: ";
   cin >> FileName;

   strcat (FileName, ".bmp");
   readGSBMP(FileName, anotherimage);



    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
                image[i][j] = ((anotherimage[i][j]) + (image[i][j])) / 2 ;
        }
    }



}
void blur(){

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            image[i][j] = ((image[i][j])+(image[i+1][j+1])+(image[i+2][j+2])+(image[i+3][j+3])+(image[i+4][j+4])+(image[i+5][j+5])) / 6 ;



        }
    }


}
void shrink(){
    unsigned char temp[SIZE][SIZE];
    string dim ;
    int x ;
    while(true)
    {
        cout << "Shrink to (1/2), (1/3) or (1/4)? : " ;
        cin >> dim ;
        if(dim == "1/2")
        {
            x = 2 ;
            break ;
        }
        else if(dim == "1/3")
        {
            x = 1 ;
            break ;
        }
        else if(dim == "1/4")
        {
            x = 0 ;
            break ;
        }
        else
            cout <<"wrong choice !!" << endl <<endl ;
    }
    while(x < 3)
    {
        for(int i = 0 , ii = 0 ; i < SIZE ; ii++ , i +=2)
        {
            for(int j = 0 , jj = 0 ; j < SIZE ; jj++ , j +=2)
            {

                temp[ii][jj] = (image[i][j] + image[i+1][j] + image[i][j+1] + image[i+1][j+1])/4 ;

            }
        }
        for(int i = 0 ; i < SIZE ; i++)
            for(int j = 0 ; j <= SIZE ; j++)
            {
                if(i >= SIZE/2 || j >= SIZE/2)
                    image[i][j] = 255 ;
                else
                    image[i][j] = temp[i][j] ;
            }
        x++ ;


    }
}




