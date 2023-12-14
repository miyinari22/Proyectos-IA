function seleccionRuletaPorCosto()
    % Solicita al usuario el tamaño de la población
    tam = input('Ingrese el tamaño de la población: ');
    
    % Genera costos aleatorios en el rango de 1 a 100
    costos = randi([1, 100], 1, tam);
    
    % Calcula Cj para cada individuo
    Nbuenos = tam;
    Cj = costos - costos(Nbuenos) + 1;  % Corrección
    
    % Inicializa Pj como un vector de ceros
    Pj = zeros(1, tam);
    
    % Calcula la sumatoria de Cj para el cálculo de Pj
    sumatoriaCj = sum(Cj(1:Nbuenos));
    
    % Calcular Pj
    for i = 1:tam
        Pj(i) = Cj(i) / sumatoriaCj;
    end
    
    % Inicializa el vector de parejas
    parejas = zeros(1, tam);
    
    % Calcula la cantidad de parejas a seleccionar (50% de la población)
    numParejas = round(tam / 2);
    
    % Realiza la selección de parejas
    for i = 1:numParejas
        % Selecciona una pareja utilizando la ruleta
        r = rand();  % Genera un número aleatorio entre 0 y 1
        acumulado = 0;
        pareja1 = 0;
        pareja2 = 0;
        for j = 1:tam
            acumulado = acumulado + Pj(j);
            if r <= acumulado
                pareja1 = j;
                break;
            end
        end
        
        % Asegura que no se seleccione el mismo individuo como pareja
        while true
            r = rand();
            acumulado = 0;
            for j = 1:tam
                acumulado = acumulado + Pj(j);
                if r <= acumulado && j ~= pareja1
                    pareja2 = j;
                    break;
                end
            end
            if pareja2 ~= 0
                break;
            end
        end
        
        % Almacena las parejas seleccionadas
        parejas(i, 1) = pareja1;
        parejas(i, 2) = pareja2;
    end
    
    % Muestra los resultados
    fprintf('j\tindividuo\tcosto\tCj\tPj\tSum\n');
    sumPj = 0; % Inicializamos la sumatoria de Pj
    for j = 1:tam
        Pj(j) = Cj(j) / sumatoriaCj;
        sumPj = sumPj + Pj(j);
        fprintf('%d\t%d\t%d\t%d\t%f\t%f\n', j, j, costos(j), Cj(j), Pj(j), sumPj);
    end
    
    fprintf('Sumatoria de Pj: %f\n', sumPj);
    fprintf('Parejas seleccionadas:\n');
    disp(parejas);
end
