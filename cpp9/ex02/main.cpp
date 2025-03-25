/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:34:10 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/25 15:35:52 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void printVector(const std::vector<int>& vec) {
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void printList(const std::list<int>& lst) {
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

std::list<int> mergeLists(const std::list<int>& left, const std::list<int>& right)
{
    std::list<int> result;
    std::list<int>::const_iterator it1 = left.begin(), it2 = right.begin();

    while (it1 != left.end() && it2 != right.end()) {
        if (*it1 < *it2) {
            result.push_back(*it1);
            ++it1;
        } else {
            result.push_back(*it2);
            ++it2;
        }
    }
    result.insert(result.end(), it1, left.end());
    result.insert(result.end(), it2, right.end());
    return result;
}

std::list<int> mergeSort(std::list<int>& lst) {
    if (lst.size() <= 1) return lst;

    std::list<int> left, right;
    std::list<int>::iterator mid = lst.begin();
    std::advance(mid, lst.size() / 2);

    left.splice(left.begin(), lst, lst.begin(), mid);
    right.splice(right.begin(), lst);

    left = mergeSort(left);
    right = mergeSort(right);

    return mergeLists(left, right);
}

void mergeInsertionSort(std::list<int>& lst) {
    if (lst.size() <= 1)
		return ;

    std::list<int> sortedPairs, remaining;
    std::list<int>::iterator it = lst.begin();

    while (it != lst.end()) {
        std::list<int>::iterator nextIt = it;
        ++nextIt;

        if (nextIt != lst.end()) {
            if (*it > *nextIt) std::swap(*it, *nextIt);
            sortedPairs.push_back(*nextIt);
            remaining.push_back(*it);
            std::advance(it, 2);
        } else {
            remaining.push_back(*it);
            ++it;
        }
    }

    sortedPairs = mergeSort(sortedPairs);

    for (std::list<int>::iterator it = remaining.begin(); it != remaining.end(); ++it) {
        std::list<int>::iterator insertPos = sortedPairs.begin();
        while (insertPos != sortedPairs.end() && *insertPos < *it) {
            ++insertPos;
        }
        sortedPairs.insert(insertPos, *it);
    }

    lst = sortedPairs;
}

void mergeInsertionSort(std::vector<int>& arr)
{
	int n = arr.size();
    if (n <= 1) return;

    std::vector<int> sortedPairs;
    std::vector<int> remaining;

    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1]) 
            std::swap(arr[i], arr[i + 1]);
        sortedPairs.push_back(arr[i + 1]);
        remaining.push_back(arr[i]);
    }

    if (arr.size() % 2 == 1) 
        remaining.push_back(arr.back());

    std::sort(sortedPairs.begin(), sortedPairs.end());

    for (size_t i = 0; i < remaining.size(); ++i) {
        std::vector<int>::iterator pos = std::lower_bound(sortedPairs.begin(), sortedPairs.end(), remaining[i]);
        sortedPairs.insert(pos, remaining[i]);
    }

    arr = sortedPairs;
}

int	checkRepeat(std::vector<int> arr)
{
	std::sort(arr.begin(), arr.end());
    for (size_t i = 1; i < arr.size(); ++i)
	{
        if (arr[i] == arr[i - 1])
			return true;
    }
    return false;
}

bool validArg(std::string arg)
{
	for (size_t i = 0; i < arg.length(); i++)
	{
		if ((arg[i] > '9' || arg[i] < '0') && arg[i] != '\0')
			return 0;
	}
	return 1;
}

bool initialDebug(int argc, char **argv, PmergerMe& data)
{
	if (argc < 2)
		return (std::cout << "Error: No parameters.\n", 0);
	int i = 0;
	while (argv[++i])
	{
		if (!validArg(argv[i]))
			return (std::cout << "Error: Incorrect Parameter: " << argv[i] << std::endl, 0);
		try
		{
			data.addNum(atoi(argv[i]));
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
			return 0;
		}
	}
	if (checkRepeat(data.getvec()))
		return (std::cout << "Error: Repeated Parameter." << std::endl, 0);
	return 1;
}

int main(int argc, char **argv)
{
	PmergerMe data;
	if (!initialDebug(argc, argv, data))
		return 1;
	clock_t start, end;
	start = clock();
    std::vector<int> vec = data.getvec();
    mergeInsertionSort(vec);
    data.setvec(vec);
	end = clock();
	double timevec = (double(end - start) / CLOCKS_PER_SEC) * 1000;
	start = clock();
	std::list<int> lst = data.getlst();
    mergeInsertionSort(lst);
	end = clock();
	double timelst = (double(end - start) / CLOCKS_PER_SEC) * 1000;
	std::cout << "Before: ";
	int i = 0;
	while (argv[++i])
		std::cout << argv[i] << " ";
	std::cout << '\n';
	std::cout << "After: ";
	printList(lst);
	std::cout << "Time to process a range of "<< argc - 1 <<" elements with std::vector : " << timevec << "ms" << std::endl;
	std::cout << "Time to process a range of "<< argc - 1 <<" elements with std::list : " << timelst << "ms" << std::endl;
}