def create_class(count):
    class_tree = {}
    for __ in range(count):
        string_class_creating = input()
        if len(string_class_creating.split()) == 1:
            key = string_class_creating
            value = []
        else:
            key, value = string_class_creating.split(' : ')
            value = value.split(' ')
        class_tree[key] = value

    not_obvious_classes = list(set(sum([val for val in class_tree.values()], [])))

    print(not_obvious_classes)
    for cl in not_obvious_classes:
        if cl not in class_tree.keys():
            class_tree[cl] = []

    return class_tree


def check_parent(tree, parent, child):
    if child not in tree.keys():
        return False
    elif parent in tree[child] or parent == child:
        return True
    elif not tree[child]:
        return False

    for val in tree[child]:
        if check_parent(tree, parent, val):
            return True

    return False


def first_task():
    n = int(input())
    tree = create_class(n)
    print(tree)
    answers = []
    q = int(input())
    for __ in range(q):
        string_request = input().split(' ')
        if check_parent(tree, string_request[0], string_request[1]):
            answers.append('Yes')
        else:
            answers.append('No')
    for answer in answers:
        print(answer)


def main():
    first_task()


if __name__ == '__main__':
    main()
