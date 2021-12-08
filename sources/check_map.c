/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:29:17 by jmilson-          #+#    #+#             */
/*   Updated: 2021/12/08 19:41:48 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 1. mapa tem que ser do tipo .ber
   
   2. soh pode ter ATÉ 5 tipos de characteres diferentes: 0, 1, C, E (0 for an 
   empty space, 1 for a wall, C for a collectible, E for map exit and P for 
   the player’s starting position.) 
   
   3. tem que ter muros em volta

   4. tem que ter uma saida, posicao e PELO MENOS UM ITEM pra coletar.

   5. tem que ser retangular

   SE O MAPA FALHAR EM ALGUM DESTES REQUISITOS devolver um "Error\n" e 
   especificar qual tipo de erro que foi.

   obs. nao precisa verificar se tem caminho valido!
   
*/