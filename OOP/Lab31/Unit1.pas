unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ExtCtrls;

type
  TForm1 = class(TForm)
    Image1: TImage;
    procedure FormPaint(Sender: TObject);
  end;

  TRectang = class
  private
    coord: Array [0..3] of Integer;
  public
    Constructor Create(left, top, right, bottom: Integer); Overload;
  published
    Constructor Create(topLeft, bottomRight: TPoint); Overload;
  end;

  TTriangle = class
  private
    points: Array [0..2] of TPoint;
  public
    Constructor Create(p1, p2, p3: TPoint); Overload;
    Constructor Create(x1, y1, x2, y2, x3, y3: Integer); Overload;
    procedure Draw(Canvas: TCanvas);
  end;

var
  Form1: TForm1;

implementation
{$R *.dfm}

Constructor TRectang.Create(left, top, right, bottom: Integer);
Begin
  coord[0] := left;
  coord[1] := top;
  coord[2] := right;
  coord[3] := bottom;
End;

Constructor TRectang.Create(topLeft, bottomRight: TPoint);
Begin
  coord[0] := topLeft.X;
  coord[1] := topLeft.Y;
  coord[2] := bottomRight.X;
  coord[3] := bottomRight.Y;
End;

Constructor TTriangle.Create(p1, p2, p3: TPoint);
Begin
  points[0] := p1;
  points[1] := p2;
  points[2] := p3;
End;

Constructor TTriangle.Create(x1, y1, x2, y2, x3, y3: Integer);
Begin
  points[0] := Point(x1, y1);
  points[1] := Point(x2, y2);
  points[2] := Point(x3, y3);
End;

procedure TTriangle.Draw(Canvas: TCanvas);
Begin
  Canvas.Polygon(points);
End;

procedure TForm1.FormPaint(Sender: TObject);
var
  rect1, rect2: TRectang;
  triangle1, triangle2: TTriangle;
  point1, point2: TPoint;
Begin
  Image1.Canvas.Brush.Color := clWhite;
  Image1.Canvas.FillRect(Rect(0, 0, Image1.Width, Image1.Height));

  point1 := Point(20, 20);
  point2 := Point(80, 80);

  rect1 := TRectang.Create(10, 10, 50, 50);
  rect2 := TRectang.Create(point1, point2);

  triangle1 := TTriangle.Create(Point(100, 100), Point(150, 100), Point(125, 150));
  triangle2 := TTriangle.Create(200, 200, 250, 200, 225, 250);

  With Image1.Canvas do
  Begin
    Pen.Width := 3;
    Pen.Color := clRed;
    Rectangle(rect1.coord[0], rect1.coord[1], rect1.coord[2], rect1.coord[3]);
    triangle1.Draw(Image1.Canvas);

    Pen.Width := 4;
    Pen.Color := clGreen;
    Rectangle(rect2.coord[0], rect2.coord[1], rect2.coord[2], rect2.coord[3]);
    triangle2.Draw(Image1.Canvas);
  End;
End;

end.
