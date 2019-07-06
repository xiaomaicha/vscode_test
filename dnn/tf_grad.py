import tensorflow as tf
from math import pi
import numpy as np
import matplotlib.pyplot as plt

tfe = tf.contrib.eager
tfe.enable_eager_execution()


# x = tf.random_uniform([2, 2])
#
# with tf.Session() as sess:
#     for i in range(x.shape[0]):
#         for j in range(x.shape[1]):
#             print(sess.run(x[i, j]))

def f(x):
    return tf.square(tf.sin(x))

def grad(f):
    return lambda x: tfe.gradients_function(f)(x)[0]

assert f(pi / 2).numpy() == 1.0
# sess = tf.Session()
grad_f = tfe.gradients_function(f)
print(grad_f(np.zeros(1))[0].numpy())

x = tf.lin_space(-2 * pi, 2 * pi, 100)
print(grad(f)(x).numpy())
x = x.numpy()

plt.plot(x, f(x).numpy(), label="f")
plt.plot(x, grad(f)(x).numpy(), label="first derivative")  # 一阶导
plt.plot(x, grad(grad(f))(x).numpy(), label="second derivative")  # 二阶导
plt.plot(x, grad(grad(grad(f)))(x).numpy(), label="third derivative")  # 三阶导
plt.legend()
plt.show()
