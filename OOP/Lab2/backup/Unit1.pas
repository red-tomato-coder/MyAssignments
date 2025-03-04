program Unit1;

uses
  FactoryManager, SpherePas;

var
  MySphere, nSphere: TSphere;
  MyFactory: TFactoryManager;
  newRadius: Real;
  i: Integer;
  total, supposedToBeDefect: Integer;

begin
  MySphere := TSphere.Create;
  MySphere.DisplayStatistics;
  Writeln('===========');

  nSphere := TSphere.Create(15.1);
  nSphere.DisplayStatistics;
  Writeln('***********');

  newRadius := 5.1;
  MySphere.SetRadius(newRadius);
  Writeln('Нова довжина = ', 2.0 * Pi * MySphere.GetRadius:10:5);
  MySphere.DisplayStatistics;

  Writeln('===========');
  MyFactory := TFactoryManager.Create;

  Writeln('Введіть кількість продуктів необхіжних: ');
  Readln(total);
  if total = '' then
     total := 10;
  Writeln('Введіть через скільки кожен продукт має бути дефектним');
  Readln(supposedToBeDefect);
  if supposedToBeDefect = '' then
     supposedToBeDefect := 3;

  for i := 1 to total do
    MyFactory.ProduceItem(i mod supposedToBeDefect = 0); // Кожен третій дефектний

  Writeln('Вироблено продуктів: ', MyFactory.GetProducedCount);
  Writeln('Відсоток дефектних продуктів: ', MyFactory.GetDefectRate:0:2, '%');

  MyFactory.ResetProduction;
  Writeln('Після скидання вироблення продуктів: ', MyFactory.GetProducedCount);

  Readln;
end.
