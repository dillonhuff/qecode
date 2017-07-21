import numpy as np
import matplotlib.pyplot as plt
 
# data to plot
n_groups = 2
opt_scores = (0.19, 0.35)
no_opt_scores = (0.32, 0.42)
 
# create plot
fig, ax = plt.subplots()
index = np.arange(n_groups)
bar_width = 0.35
opacity = 0.8
 
rects1 = plt.bar(index, no_opt_scores, bar_width,
                 alpha=opacity,
                 color='b',
                 label='No analytic root optimization')
 
rects2 = plt.bar(index + bar_width, opt_scores, bar_width,
                 alpha=opacity,
                 color='r',
                 label='Analytic root optimization')
 
plt.xlabel('Intersection Test')
plt.ylabel('Benchmark Time')
plt.title('Effect of Analytic Root Finding Optimization')
plt.xticks(index + bar_width, ('Circle-Ellipse', 'Ellipsoid-Plane'))
plt.legend()
 
plt.tight_layout()
plt.show()
