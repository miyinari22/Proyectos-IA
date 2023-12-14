function tiro

XA = load('new-thyroid.txt');
[m,n] = size(XA);
XA = XA';

temp = XA(1, :);  % Almacena temporalmente los datos de la fila 1
XA(1, :) = XA(6, :);  % Asigna los datos de la fila 6 a la fila 1
XA(6, :) = temp;  % Asigna los datos temporales (de la fila 1) a la fila 6

X = [XA(1:5,1:75) XA(1:5,151:167) XA(1:5,186:200)];
t = [XA(6,1:75) XA(6,151:167) XA(6,186:200)];
P = [XA(1:5,76:150) XA(1:5,168:185) XA(1:5,200:215)];
tp = [XA(6,76:150) XA(6,168:185) XA(6,200:215)];
% Generamos la estructura
RN = newff(minmax(X),[5,10,8,8,1],{'logsig','tansig','logsig','tansig','purelin'},'trainscg');
RNE = train(RN,X,t);
Y = sim(RNE, X)
YP = sim(RNE, P)

% Calculamos el porcentaje de clasificación correcta para el conjunto de entrenamiento
accuracy_train = calcularPorcentajeClasificacion(Y, t);
fprintf('Porcentaje de clasificación correcta para el conjunto de entrenamiento: %.2f%%\n', accuracy_train);

% Calculamos el porcentaje de clasificación correcta para el conjunto de prueba
accuracy_test = calcularPorcentajeClasificacion(YP, tp);
fprintf('Porcentaje de clasificación correcta para el conjunto de prueba: %.2f%%\n', accuracy_test);

% Función para calcular el porcentaje
function accuracy = calcularPorcentajeClasificacion(outputs, targets)
    % Comparación
    correct = sum(round(outputs) == targets);
    accuracy = correct / numel(targets) * 100; % Porcentaje de clasificación correcta
end

end  % Termina la función tiroides
