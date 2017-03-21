class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

class LinkedList:
	def __init__(self):
		self.head = None

	def print_list(self):
		temp = self.head
		while temp:
			print(temp.data)
			temp = temp.next

if __name__ == '__main__':
	linked_list = LinkedList()

	linked_list.head = Node(1)
	second = Node(2)
	third = Node(3)

	linked_list.head.next = second
	second.next = third

	linked_list.print_list()