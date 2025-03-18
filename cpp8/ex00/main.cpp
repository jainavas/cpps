/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:48:00 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/18 16:48:44 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	try {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);

        std::cout << "Testing with vector..." << std::endl;
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;

        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        
        std::cout << "Testing with list..." << std::endl;
        std::list<int>::iterator it2 = easyfind(lst, 25);
        std::cout << "Found: " << *it2 << std::endl; // This won't be executed
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
