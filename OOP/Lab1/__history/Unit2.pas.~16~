unit Unit2;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes,
  Vcl.Graphics, Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.ExtCtrls,
  Vcl.Buttons, Vcl.ComCtrls, Math;

type
  Vector = array[0..1000] of Real;
  Vec = array[0..50] of Real;
  TForm2 = class(TForm)
    PageControl1: TPageControl;
    TabSheet1: TTabSheet;
    TabSheet2: TTabSheet;
    GroupBox1: TGroupBox;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Label10: TLabel;
    Edital: TEdit;
    Editbl: TEdit;
    EditNg: TEdit;
    EditNe: TEdit;
    Button1: TButton;
    ComboBox1: TComboBox;
    ComboBox2: TComboBox;
    ComboBox3: TComboBox;
    ComboBox4: TComboBox;
    Image1: TImage;
    RadioGroup1: TRadioGroup; // Options: 1/(1+x+x²) and x²–x (for integration)
    RadioGroup2: TRadioGroup; // Options: Midpoint, Simpson, Trapezoid methods
    LabelResult: TLabel;
    Button2: TButton; // Integration execution button
    ComboBox5: TComboBox; // Function selector for Fourier series (sin(x), cos(x), etc.)
    EditA: TEdit;
    EditB: TEdit;
    EditN: TEdit;
    EditEps: TEdit;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
    function MidpointMethod(a, b, eps: Double; var N: Integer): Double;
    function TrapezoidMethod(a, b, eps: Double; var N: Integer): Double;
    function SimpsonMethod(a, b, eps: Double; var N: Integer): Double;
  end;

var
  Form2: TForm2;
  Xe, Ye: Vector;
  Xg, Yg: Vector;
  a, b, c: Vec;
  Ne, Ngr: Integer;
  Ng: Integer;
  Tp: Real;
  al, bl: Real;

implementation

{$R *.dfm}

{ --- Fourier series function to tabulate --- }
function f(x: Real): Real;
begin
  if Form2.ComboBox5.Text = 'sin(x)' then
    Result := sin(x)
  else if Form2.ComboBox5.Text = 'cos(x)' then
    Result := cos(x)
  else if Form2.ComboBox5.Text = 'sin(x)*cos(x)+1' then
    Result := sin(x) * cos(x) + 1
  else
    Result := sin(x);  // Default case
end;

{ --- Integration function based on RadioGroup1 selection --- }
function IntFunc(x: Double): Double;
begin
  if Form2.RadioGroup1.ItemIndex = 0 then
    Result := 1 / (1 + x + x * x)
  else if Form2.RadioGroup1.ItemIndex = 1 then
    Result := x * x - x
  else
    Result := 1 / (1 + x + x * x);
end;

{ --- Tabulate the function f over [al, bl] using Ne subintervals --- }
procedure TabF(var Xe: Vector; var Ye: Vector);
var
  h: Real;
  idx: Integer;
begin
  h := (bl - al) / Ne;
  Xe[0] := al;
  for idx := 0 to Ne - 1 do
  begin
    Ye[idx] := f(Xe[idx]);
    Xe[idx + 1] := Xe[idx] + h;
  end;
  Ye[Ne] := f(Xe[Ne]); // Compute the last value
end;

{ --- Compute Fourier series coefficients and the Fourier sum --- }
procedure Furje(Xe, Ye: Vector; Ne: Integer; var Yg: Vector);
var
  i, k: Integer;
  w, KOM, S, D: Real;
begin
  Ng := StrToInt(Form2.EditNg.Text); // number of harmonics
  Tp := bl - al; // period
  w := 2 * Pi / Tp;
  // Compute coefficients a[k], b[k] for k = 1..Ng (using all Ne+1 points)
  for k := 1 to Ng do
  begin
    S := 0.0;
    D := 0.0;
    for i := 0 to Ne do
    begin
      KOM := k * w * Xe[i];
      S := S + Ye[i] * cos(KOM);
      D := D + Ye[i] * sin(KOM);
    end;
    a[k] := 2 * S / (Ne + 1);
    b[k] := 2 * D / (Ne + 1);
    c[k] := Sqrt(Sqr(a[k]) + Sqr(b[k]));
  end;
  // Compute a[0] as the average value
  a[0] := 0.0;
  for i := 0 to Ne do
    a[0] := a[0] + Ye[i];
  a[0] := a[0] / (Ne + 1);
  // Build the Fourier series sum at each tabulated x value
  for i := 0 to Ne do
  begin
    S := 0.0;
    for k := 1 to Ng do
    begin
      KOM := k * w * Xe[i];
      S := S + a[k] * cos(KOM) + b[k] * sin(KOM);
    end;
    Yg[i] := a[0] + S;
  end;
end;

{ --- Visualize the amplitudes of the harmonics --- }
procedure Garm(Ng: Integer; c: Vec);
var
  i, krokx: Integer;
  MaxC, ky, w: Real;
  x: Integer;
begin
  // Use a horizontal margin of 20 (i.e. total margin = 40)
  krokx := (Form2.Image1.Width - 40) div Ng;
  MaxC := c[1];
  for i := 2 to Ng do
    if c[i] > MaxC then
      MaxC := c[i];
  if MaxC = 0 then MaxC := 1; // Prevent division by zero
  ky := (Form2.Image1.Height div 2) / MaxC;
  with Form2.Image1.Canvas do
  begin
    Pen.Color := clHighlight;
    Pen.Width := 2;
    // Draw a simple coordinate frame for the harmonic amplitudes
    MoveTo(20, 40);
    LineTo(30, 30);
    LineTo(40, 40);
    MoveTo(30, 30);
    LineTo(30, Form2.Image1.Height - 50);
    LineTo(Form2.Image1.Width - 20, Form2.Image1.Height - 50);
    MoveTo(Form2.Image1.Width - 40, Form2.Image1.Height - 60);
    LineTo(Form2.Image1.Width - 20, Form2.Image1.Height - 50);
    LineTo(Form2.Image1.Width - 40, Form2.Image1.Height - 40);
    TextOut(18, 20, 'C');
    TextOut(Form2.Image1.Width - 50, Form2.Image1.Height - 25, 'W');
    Pen.Color := clLime;
    Pen.Width := 2;
    x := krokx + 20;
    w := 2 * Pi / (bl - al);
    for i := 1 to Ng do
    begin
      MoveTo(Round(x) + 3, Form2.Image1.Height - 50);
      LineTo(Round(x) + 3, Form2.Image1.Height - 50 - Round(ky * c[i]));
      TextOut(Round(x), Form2.Image1.Height - Round(ky * c[i]) - 65,
        FloatToStrF(c[i], ffGeneral, 0, 0));
      Ellipse(Round(x), Form2.Image1.Height - 53, Round(x) + 5,
        Form2.Image1.Height - 48);
      Ellipse(Round(x) + 1, Form2.Image1.Height - 50 - Round(ky * c[i]),
        Round(x) + 7, Form2.Image1.Height - 50 - Round(ky * c[i]) + 5);
      x := x + krokx;
    end;
    x := krokx + 19;
    TextOut(Round(x), Form2.Image1.Height - 30,
      'W=' + FloatToStrF(w, ffGeneral, 0, 0));
  end;
end;

{ --- Integration Methods --- }

function TForm2.MidpointMethod(a, b, eps: Double; var N: Integer): Double;
var
  steps: Integer;
  prevResult, resultValue, h, sum, x: Double;
begin
  steps := 0;
  prevResult := Infinity;
  resultValue := 0.0;

  while True do
  begin
    h := (b - a) / N;
    sum := 0.0;

    for var i := 1 to N do
    begin
      x := a + h * (i - 0.5);
      sum := sum + IntFunc(x);
    end;

    resultValue := h * sum;
    Inc(steps);

    if Abs(resultValue - prevResult) < eps then
      Break;

    prevResult := resultValue;
    N := N * 2;
  end;

  Result := resultValue;
end;

function TForm2.TrapezoidMethod(a, b, eps: Double; var N: Integer): Double;
var
  steps: Integer;
  prevResult, resultValue, h, sum, x, fa, fb: Double;
begin
  steps := 0;
  prevResult := Infinity;
  resultValue := 0.0;

  while True do
  begin
    h := (b - a) / N;
    sum := 0.0;

    for var i := 1 to N - 1 do
    begin
      x := a + i * h;
      sum := sum + IntFunc(x);
    end;

    fa := IntFunc(a);
    fb := IntFunc(b);

    resultValue := h * (fa + fb + 2 * sum) / 2.0;
    Inc(steps);

    if Abs(resultValue - prevResult) < eps then
      Break;

    prevResult := resultValue;
    N := N * 2;
  end;

  Result := resultValue;
end;

function TForm2.SimpsonMethod(a, b, eps: Double; var N: Integer): Double;
var
  steps: Integer;
  prevResult, resultValue, h, sumOdd, sumEven, x, fa, fb: Double;
begin
  steps := 0;
  prevResult := Infinity;
  resultValue := 0.0;

  while True do
  begin
    // Ensure N is even for Simpson's rule
    if (N mod 2) <> 0 then
      N := N + 1;

    h := (b - a) / N;
    sumOdd := 0.0;
    sumEven := 0.0;

    for var i := 1 to N - 1 do
    begin
      x := a + i * h;
      if (i mod 2) = 1 then
        sumOdd := sumOdd + IntFunc(x)
      else
        sumEven := sumEven + IntFunc(x);
    end;

    fa := IntFunc(a);
    fb := IntFunc(b);

    resultValue := h * (fa + fb + 4 * sumOdd + 2 * sumEven) / 6.0;
    Inc(steps);

    if Abs(resultValue - prevResult) < eps then
      Break;

    prevResult := resultValue;
    N := N * 2;
  end;

  Result := resultValue;
end;

{ --- Button1Click: Fourier Series Tabulation, Computation and Drawing --- }
procedure TForm2.Button1Click(Sender: TObject);
var
  i: Integer;
  krokx, kroky: Integer;
  minYg, maxYg, maxx, minx, maxy, miny: Real;
  kx, ky: Real;
  ox, oy: Integer;
begin
  // Read the number of subintervals and interval bounds for the Fourier series
  Ne := StrToInt(EditNe.Text);
  al := StrToFloat(Edital.Text);
  bl := StrToFloat(Editbl.Text);

  // Tabulate the function and compute its Fourier series approximation
  TabF(Xe, Ye);
  Furje(Xe, Ye, Ne, Yg);

  // Determine the min and max values for both functions
  minYg := Yg[0];
  maxYg := Yg[0];
  for i := 1 to Ne do
  begin
    if Yg[i] > maxYg then maxYg := Yg[i];
    if Yg[i] < minYg then minYg := Yg[i];
  end;
  minx := Xe[0];
  maxx := Xe[Ne];
  miny := Ye[0];
  maxy := Ye[0];
  for i := 1 to Ne do
  begin
    if Ye[i] > maxy then maxy := Ye[i];
    if Ye[i] < miny then miny := Ye[i];
  end;
  if maxy < maxYg then maxy := maxYg;
  if miny > minYg then miny := minYg;

  // Set up scaling (we use a margin of 20 pixels around the TImage)
  kx := (Image1.Width - 40) / (maxx - minx);
  ky := (Image1.Height - 40) / (maxy - miny);

  // Compute the pixel position of the x-axis (y=0) and y-axis (x=0)
  if (minx < 0) and (maxx > 0) then
    ox := 20 + Round((0 - minx) * kx)
  else if maxx <= 0 then
    ox := 20 + Round((maxx - minx) * kx)
  else
    ox := 20;
  if (miny < 0) and (maxy > 0) then
    oy := Image1.Height - 20 - Round((0 - miny) * ky)
  else if maxy <= 0 then
    oy := Image1.Height - 20 - Round((maxy - miny) * ky)
  else
    oy := Image1.Height - 20;

  // Draw the graphs
  with Image1 do
  begin
    // Clear the image
    Canvas.Brush.Color := clWhite;
    Canvas.FillRect(Rect(0, 0, Width, Height));
    // Draw a border
    Canvas.Pen.Width := 2;
    Canvas.Pen.Color := clPurple;
    Canvas.Rectangle(1, 1, Width - 1, Height - 1);

    // Draw grid lines (10 divisions)
    Canvas.Pen.Color := clSilver;
    Canvas.Pen.Width := StrToInt(ComboBox4.Text);
    krokx := (Width - 40) div 10;
    kroky := (Height - 40) div 10;
    for i := 0 to 10 do
    begin
      Canvas.MoveTo(20, 20 + i * kroky);
      Canvas.LineTo(Width - 20, 20 + i * kroky);
      Canvas.MoveTo(20 + i * krokx, 20);
      Canvas.LineTo(20 + i * krokx, Height - 20);
    end;

    // Draw the coordinate axes
    Canvas.Pen.Color := clBlack;
    Canvas.Pen.Width := StrToInt(ComboBox3.Text);
    Canvas.MoveTo(20, oy);
    Canvas.LineTo(Width - 20, oy);
    Canvas.MoveTo(ox, 20);
    Canvas.LineTo(ox, Height - 20);

    // Draw the original function (Ye) in red
    Canvas.Pen.Color := clRed;
    Canvas.Pen.Width := StrToInt(ComboBox2.Text);
    Canvas.MoveTo(20 + Round((Xe[0] - minx) * kx),
                  Height - 20 - Round((Ye[0] - miny) * ky));
    for i := 1 to Ne do
      Canvas.LineTo(20 + Round((Xe[i] - minx) * kx),
                    Height - 20 - Round((Ye[i] - miny) * ky));

    // Draw the Fourier series approximation (Yg) in lime
    Canvas.Pen.Color := clLime;
    Canvas.Pen.Width := StrToInt(ComboBox1.Text);
    Canvas.MoveTo(20 + Round((Xe[0] - minx) * kx),
                  Height - 20 - Round((Yg[0] - miny) * ky));
    for i := 1 to Ne do
      Canvas.LineTo(20 + Round((Xe[i] - minx) * kx),
                    Height - 20 - Round((Yg[i] - miny) * ky));
  end;

  // Ask the user whether to display the harmonic amplitudes.
  if MessageDlg('Показати гармоніки?', mtConfirmation, [mbYes, mbNo], 0) = mrYes then
  begin
    Image1.Picture := nil; // Clear the graph
    Garm(Ng, c);
  end;
end;

{ --- Button2Click: Integration Execution --- }
procedure TForm2.Button2Click(Sender: TObject);
var
  aVal, bVal, eps: Double;
  n: Integer;
  integralResult: Double;
begin
//  ShowMessage('DEBUUUG');
  aVal := StrToFloat(EditA.Text);
  bVal := StrToFloat(EditB.Text);
  n := StrToInt(EditN.Text);
  eps := StrToFloat(EditEps.Text);

  case RadioGroup2.ItemIndex of
    0: integralResult := MidpointMethod(aVal, bVal, eps, n);
    1: integralResult := SimpsonMethod(aVal, bVal, eps, n);
    2: integralResult := TrapezoidMethod(aVal, bVal, eps, n);
  else
    integralResult := MidpointMethod(aVal, bVal, eps, n);
  end;

  LabelResult.Caption := 'Integral = ' + FloatToStr(integralResult) + ', N = ' + IntToStr(n);
  LabelResult.Refresh;
end;

end.

