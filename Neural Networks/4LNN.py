import numpy as np

def sigmoid(x, deriv = False):
	if deriv:
		return x * (1 - x)
	return 1/(1+np.exp(-x))

# input 
x = np.array([
		[2,3,4,4],
		[5,3,4,56],
		[2,3,23,4],
		[7,6,63,34],
		[3,7,32,2]
	])

y = np.array([
		[1, 0, 0, 1, 0]
	]).T

np.random.seed(1)

syn0 = 2 * np.random.random((4, 5)) - 1
syn1 = 2 * np.random.random((5, 5)) - 1
syn2 = 2 * np.random.random((5, 1)) - 1

for _ in range(60000):
	l0 = x
	l1 = sigmoid(np.dot(l0, syn0))
	l2 = sigmoid(np.dot(l1, syn1))
	l3 = sigmoid(np.dot(l2, syn2))

	l3_error = y - l3

	if _ % 10000 == 0:
		print("Error "+ str(_/10000) +": "+str(np.mean(np.abs(l3_error))))

	l3_delta = l3_error * sigmoid(l3, deriv = True)

	l2_error = l3_delta.dot(syn2.T)

	l2_delta = l2_error * sigmoid(l2, deriv = True)
	
	l1_error = l2_delta.dot(syn1.T)

	l1_delta = l1_error * sigmoid(l1, deriv = True)

	syn2 += l2.T.dot(l3_delta)
	syn1 += l1.T.dot(l2_delta)
	syn0 += l0.T.dot(l1_delta)

print(sigmoid(np.dot(l2, syn2)))