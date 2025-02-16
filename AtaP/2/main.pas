unit Main;
{$mode objfpc}{$H+}
interface
uses
  SysUtils;

const
  N = 5;
var
  Xe, Ye: array[1..N] of Double;
  i: Integer;
  x, y: Double;
implementation
function F(x: Double): Double;
begin
  Result := x * x - 2;  // x^2 - 2
end;

begin
  // Fill Xe and Ye arrays
  for i := 1 to N do  // Start from 1 to N
  begin
    Xe[i] := i;
    Ye[i] := F(i);
  end;

  // Print the table header
  WriteLn('X      Y');
  WriteLn('---------');

  // Print the results
  for i := 1 to N do
  begin
    WriteLn(Xe[i]:6:2, '  ', Ye[i]:6:2);  // Formatting for nicer output
  end;
end.

