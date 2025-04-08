unit SphereU;

Interface
Uses SichU;

Type
  Sphere = class
  Private
    GolovSich: Sich;
  Public
    Constructor Create(x, y, z, r: Real);
    Procedure SetSphere(x, y, z, r: Real);
    Function Volume: Real;
    Function GetPoint: String;
  end;

Implementation

Constructor Sphere.Create(x, y, z, r: Real);
begin
  GolovSich := Sich.Create(x, y, z, r);
end;

Procedure Sphere.SetSphere(x, y, z, r: Real);
begin
  GolovSich.SetSich(x, y, z, r);
end;

Function Sphere.GetPoint: String;
begin
  Result := GolovSich.GetPoint;
end;

Function Sphere.Volume: Real;
begin
  Result := (4.0 / 3.0) * Pi * GolovSich.GetRad * GolovSich.GetRad * GolovSich.GetRad;
end;

end.
