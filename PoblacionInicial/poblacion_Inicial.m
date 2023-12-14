function poblacion_Inicial
    r = input('Ingrese el valor de r: ');
    tam = input('Ingrese el valor de tam: ');

    % Se verifica si r está en el rango de 2 a 4
    if r < 2 || r > 4
        error('El valor de r debe estar en el rango [2, 5].');
    end

    % Se define el conjunto de letras permitidas
    letras_permitidas = 'acgt';

    % Generar la población inicial
    poblacion_inicial = strings(tam, 1);  %Crea un arreglo de cadenas

    for i = 1:tam
        individuo = '';
        for j = 1:r
            %Selecciona una letra aleatoriamente del conjunto de letras permitidas
            letra_aleatoria = letras_permitidas(randi(length(letras_permitidas)));
            individuo = strcat(individuo, letra_aleatoria);
        end
        poblacion_inicial(i) = individuo;
    end

    % Mostrar la población generada
    disp('Población Inicial:');
    for i = 1:tam
        disp(poblacion_inicial(i));
    end
end
