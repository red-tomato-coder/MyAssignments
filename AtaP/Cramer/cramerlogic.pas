unit CramerLogic;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, Grids, StdCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Edit1: TEdit;
    Label1: TLabel;
    StringGrid1: TStringGrid;
    StringGrid2: TStringGrid;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);
var
  N: Integer;
begin
  // Retrieve the grid size from Edit1 (assuming it's the input field)
  N := StrToInt(Edit1.Text);  // Convert the text to an integer

  // Set the column and row count of the grid
  StringGrid1.ColCount := N;  // Number of columns
  StringGrid1.RowCount := N;  // Number of rows
  StringGrid2.RowCount := N;
end;

procedure TForm1.Button2Click(Sender: TObject);

var
  Matrix: array of array of Integer;
  matSize, i, j: Integer;

begin

end;

end.

