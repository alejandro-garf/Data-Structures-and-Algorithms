""" Array example """

new_list = [1, 2, 3 , 4 , 5]
result = new_list[0]
print (new_list)
print (result)

if 1 in new_list:
    print(True)
else:
    print(False)

for n in new_list:
    if n == 1:
        print (True)
        break

insert_function = new_list.insert(1, 6)
print(new_list)

append_function = new_list.append(7)
print(new_list)

delete_funtion = new_list.remove(7)
print(new_list)

print(result)