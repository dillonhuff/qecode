import numpy as np
import matplotlib.pyplot as plt
 
# data to plot
n_groups = 4
means_frank = (90, 55, 40, 65)
means_guido = (85, 62, 54, 20)
 
# create plot
fig, ax = plt.subplots()
index = np.arange(n_groups)
bar_width = 0.35
opacity = 0.8
 
rects1 = plt.bar(index, means_frank, bar_width,
                 alpha=opacity,
                 color='b',
                 label='No analytic root optimization')
 
rects2 = plt.bar(index + bar_width, means_guido, bar_width,
                 alpha=opacity,
                 color='r',
                 label='Analytic root optimization')
 
plt.xlabel('Intersection Test')
plt.ylabel('Benchmark Time')
plt.title('Effect of Analytic Root Finding Optimization')
plt.xticks(index + bar_width, ('Circle-Ellipse', 'Circle-Circle', 'Line-Line', 'Ellipsoid-Plane'))
plt.legend()
 
plt.tight_layout()
plt.show()
