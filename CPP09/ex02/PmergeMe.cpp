#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidNumber(const char *str)
{
    if (!str || str[0] == '\0')
        return false;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }

    char *ptr;
    long num = strtol(str, &ptr, 10);

    if (*ptr != '\0' || num < 0 || num > INT_MAX)
        return false;

    return true;
}

bool PmergeMe::parseArgs(int argc, char **argv)
{
    if (argc < 2)
        return false;

    for (int i = 1; i < argc; i++)
    {
        if (!isValidNumber(argv[i]))
            return (false);

        int num = atoi(argv[i]);
        _vec.push_back(num);
        _deq.push_back(num);
    }

    return true;
}



void    vectorMerge(std::vector<std::pair<int, int> >& pairs, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<std::pair<int, int> > L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = pairs[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = pairs[mid + 1 + j];

    int k = left, i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (L[i].second <= R[j].second)
        {
            pairs[k] = L[i];
            i++;
        }
        else
        {
            pairs[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        pairs[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        pairs[k] = R[j];
        j++;
        k++;
    }
}

void    vectorMergeSort(std::vector<std::pair<int, int> >& pairs, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        vectorMergeSort(pairs, left, mid);
        vectorMergeSort(pairs, mid + 1, right);
        vectorMerge(pairs, left, mid, right);
    }
}

int getJacob(size_t index)
{
    if (index <= 1)
        return index;
    return getJacob(index - 1) + 2 * getJacob(index - 2);
}

void PmergeMe::sortVector()
{
    size_t size = _vec.size();

    if (size <= 1)
        return;
    
    std::vector<std::pair<int, int> > pairs;
    int restNumber = -1;

    size_t i = 0;

    while (i + 1 < size)
    {
        int first = _vec[i];
        int second = _vec[i + 1];
        if (first > second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
        i += 2;
    }

    if (i < size)
        restNumber = _vec[i];

    vectorMergeSort(pairs, 0, pairs.size() - 1);

    std::vector<int> mainChain;
    std::vector<int> pendChain;

    for (size_t j = 0; j < pairs.size(); j++)
    {
        mainChain.push_back(pairs[j].second);
        pendChain.push_back(pairs[j].first);
    }
    int previousIndex = -1;
    int index = 0;
    int tmp = 0;
    for (size_t j = 0; j < pendChain.size(); j++)
    {
        index = getJacob(j);
        if (index < 0)
            break;
        if (index == previousIndex)
            continue;
        if (index >= (int)pendChain.size())
            index = pendChain.size() - 1;
        tmp = index;
        while (tmp > previousIndex)
        {
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pendChain[tmp]);
            mainChain.insert(pos, pendChain[tmp]);
            tmp--;
        }
        previousIndex = index;
    }
    if (restNumber != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), restNumber);
        mainChain.insert(pos, restNumber);
    }
    _vec = mainChain;
}


void    dequeMerge(std::deque<std::pair<int, int> >& pairs, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::deque<std::pair<int, int> > L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = pairs[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = pairs[mid + 1 + j];

    int k = left, i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (L[i].second <= R[j].second)
        {
            pairs[k] = L[i];
            i++;
        }
        else
        {
            pairs[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        pairs[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        pairs[k] = R[j];
        j++;
        k++;
    }
}

void    dequeMergeSort(std::deque<std::pair<int, int> >& pairs, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        dequeMergeSort(pairs, left, mid);
        dequeMergeSort(pairs, mid + 1, right);
        dequeMerge(pairs, left, mid, right);
    }
}

void PmergeMe::sortDeque()
{
    size_t size = _deq.size();

    if (size <= 1)
        return;
    
    std::deque<std::pair<int, int> > pairs;
    int restNumber = -1;

    size_t i = 0;

    while (i + 1 < size)
    {
        int first = _deq[i];
        int second = _deq[i + 1];
        if (first > second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
        i += 2;
    }

    if (i < size)
        restNumber = _deq[i];

    dequeMergeSort(pairs, 0, pairs.size() - 1);

    std::deque<int> mainChain;
    std::deque<int> pendChain;

    for (size_t j = 0; j < pairs.size(); j++)
    {
        mainChain.push_back(pairs[j].second);
        pendChain.push_back(pairs[j].first);
    }
    int previousIndex = -1;
    int index = 0;
    int tmp = 0;
    for (size_t j = 0; j < pendChain.size(); j++)
    {
        index = getJacob(j);
        if (index < 0)
            break;
        if (index == previousIndex)
            continue;
        if (index >= (int)pendChain.size())
            index = pendChain.size() - 1;
        tmp = index;
        while (tmp > previousIndex)
        {
            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pendChain[tmp]);
            mainChain.insert(pos, pendChain[tmp]);
            tmp--;
        }
        previousIndex = index;
    }
    if (restNumber != -1)
    {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), restNumber);
        mainChain.insert(pos, restNumber);
    }
    _deq = mainChain;
}

void    is_sorted(const std::vector<int>& vec)
{
    for (size_t i = 1; i < vec.size(); i++)
    {
        if (vec[i - 1] > vec[i])
        {
            std::cerr << "Vector is not sorted correctly." << std::endl;
            return;
        }
    }
    std::cout << "Vector is sorted correctly." << std::endl;
}
void PmergeMe::sort()
{
    std::vector<int> original = _vec;

    clock_t vecStart = clock();
    sortVector();
    clock_t vecEnd = clock();
    double vecTime = static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000000;
    is_sorted(_vec);
    clock_t deqStart = clock();
    sortDeque();
    clock_t deqEnd = clock();
    double deqTime = static_cast<double>(deqEnd - deqStart) / CLOCKS_PER_SEC * 1000000;

    printSeq(original, "Before");
    printSeq(_vec, "After");

    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(5)
              << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque : " << std::fixed << std::setprecision(5)
              << deqTime << " us" << std::endl;
}