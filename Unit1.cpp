//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int xFruit = 0;
int yFruit = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//-----------------------------------------------------------------------
void resetTimers()
 {
    Form1->left->Enabled = false;
    Form1->right->Enabled = false;
    Form1->up->Enabled = false;
    Form1->down->Enabled = false;

 }
 //----------------------------------------------------------------------------
 void setFruitLocation()
 {
    //randomly choosing fruit place on the field
        randomize();
        xFruit = random(400);
        yFruit = random(400);

    //prevent placing fruit on middle of the game field where will be snake at the beginning of the game
        if((xFruit > 180 && xFruit < 220) && (yFruit > 180 && yFruit < 220) )
          {
                xFruit == 100;
          }
    //locatiing fruit on the field
        Form1->fruit->Left = xFruit;
        Form1->fruit->Top =  yFruit;
 }
//---------------------------------------------------------------------------
 void setGame()
{
        setFruitLocation();
        Form1->head->Left = 200;
        Form1->head->Top = 200;

        //play intro sound
        //sndPlaySound("snd/intro.wav",SND_ASYNC);
        resetTimers();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::downTimer(TObject *Sender)
{
   head->Top += 6;
    if((head->Top + head->Height) >= playField->Height)
    {
      head->Top = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::leftTimer(TObject *Sender)
{
    head->Left -= 6;
    if((head->Left) <= 0)
    {
      head->Left = playField->Width - 10;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::rightTimer(TObject *Sender)
{
   head->Left += 6;
   if((head->Left + head->Width) > playField->Width)
    {
      head->Left = 0;
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::upTimer(TObject *Sender)
{
     head->Top -= 6;
   if(head->Top + 10  <= 0)
    {
      head->Top = playField->Height - head->Height;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        setGame();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_UP)
  {
        head->Picture->LoadFromFile("img/leb.bmp");
        resetTimers();
        up->Enabled = true;

   }
  if(Key == VK_LEFT)
  {
        head->Picture->LoadFromFile("img/lebWlewo.bmp");
        resetTimers();
        left->Enabled = true;
   }

  if(Key == VK_DOWN)
 {
        head->Picture->LoadFromFile("img/lebWdol.bmp");
        resetTimers();
        down->Enabled = true;
 }
 if(Key == VK_RIGHT)
 {
       head->Picture->LoadFromFile("img/lebWprawo.bmp");
       resetTimers();
       right->Enabled = true;
 }


}
//---------------------------------------------------------------------------

