function mutacionPorIntercambio()
    % Solicitamos al usuario que ingrese la cadena de ADN
    cadena_adn = input('Ingresa la cadena de ADN: ', 's');

    % Obtenemos la longitud de la cadena de ADN
    longitud_cadena = length(cadena_adn);

    % Generamos dos valores aleatorios diferentes entre 1 y la longitud de la cadena
    valor1 = randi(longitud_cadena);
    valor2 = randi(longitud_cadena);
    
    while valor1 == valor2
        valor2 = randi(longitud_cadena);
    end

    % Realizamos el intercambio de alelos
    alelo1 = cadena_adn(valor1);
    alelo2 = cadena_adn(valor2);
    
    % Creamos la cadena mutada
    cadena_mutada = cadena_adn;
    cadena_mutada(valor1) = alelo2;
    cadena_mutada(valor2) = alelo1;
    
    % Mostramos la cadena original y la cadena mutada
    fprintf('Cadena original: %s\n', cadena_adn);
    fprintf('Cadena mutada: %s\n', cadena_mutada);
    
    % Mostramos los valores aleatorios (posiciones) intercambiados
    fprintf('Valores aleatorios intercambiados: %d y %d\n', valor1, valor2);
end
