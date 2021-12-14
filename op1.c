/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:53:45 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/12 15:43:28 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    sab (int *p)
{
    int temp; 

    temp = p[0];
    p[0] = p[1];
    p[1] = temp;
}

void    pab (char *p1, char *p2)
{
    int *temp;

    temp = p1[0];
    if (p2)
    {






    }
}

void    rab (char *p)
{
    int temp;
    int x;

    temp = p[0];
    x = 0;
    if (a)
    {
        while (p[x + 1])
        {
            p[x] = p[x + 1];
            x++;
        }
        if (x)
            p[x] = temp;
    }  
}

void    rrab (char *p)
{
    int temp;
    int x;

    x = -1;
    temp = 0
    while(p[x + 1])
        x++;
    if (x > 0)
    {
        temp = p[x];
        while (x)
        {
            x--;
            p[x + 1] = p[x];
        }
        p[0] = temp;
    }
}
