def insertion_sort(array):
	new_array = []
	for element in array:
		if len(new_array) == 0:
			new_array.insert(0,element)
		else:
			inserted = False
			for i in range(len(new_array)):
				if new_array[i] > element:
					new_array.insert(i, element)
					inserted = True
					break
			if not inserted:
				new_array.insert(len(new_array), element)

	return new_array

def merge(array, p, q, r):
	n1 = q-p+1
	n2 = r-q

def check_sort(array):
	return sorted(array) == insertion_sort(array)

if __name__ == "__main__":
	n = map(int, raw_input().split())
	print check_sort(n)