#include "../library/TreeMap.h"
#include "../library/values/values.h"
#include <stdio.h>

int main()
{
    printf("Enter space-separated numbers, 0 will stop input: ");

    TreeMap* map = createTreeMap(compare);

    int input = 0;
    while (scanf("%d", &input) == 1 && input != 0) {
        Value number = wrapInt(input);
        if (hasKey(map, number)) {
            int currentCount = getInt(get(map, number));
            put(map, number, wrapInt(currentCount + 1));
        } else
            put(map, number, wrapInt(1));
    }

    printf("Number Amount\n");
    for (TreeMapIterator iterator = getIterator(map); hasElement(&iterator); next(&iterator)) {
        int key = getInt(getKey(&iterator));
        int value = getInt(getValue(&iterator));
        printf("%d: %d\n", key, value);
    }

    deleteTreeMap(map);

    return 0;
}