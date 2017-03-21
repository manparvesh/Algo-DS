import numpy as np

# sigmoid function
def nonlin(x, deriv = False):
	if (deriv):
		return x * (1 - x)
	return 1 / (1 + np.exp(-x))

# input
x = np.array([
		[0, 0, 1],
		[0, 1, 1],
		[1, 0, 1],
		[1, 1, 1]
	])

# output
y = np.array([
		[0, 0, 1, 1]
	]).T

#seed random numbers to make calculation deterministic
np.random.seed(1)

# init weights randomly with mean 0
syn0 = 2 * np.random.random((3, 1)) - 1

for iter in range(10**4):

	# forward propagation
	l0 = x
	l1 = nonlin(np.dot(l0, syn0))

	# how much did we deviate from the output?
	l1_error = y - l1 # find the distance from the correct answer

	# multiply how much we missed by the 
	# slope of the sigmoid at the values in l1
	l1_delta = l1_error * nonlin(l1, True) # move to that direction 

	syn0 += np.dot(l0.T, l1_delta)

print("after training")
print(l1)