# Pyton program to read data and plot the Convex hull

import matplotlib.pyplot as plt
from matplotlib.figure import Figure
from matplotlib.animation import FuncAnimation
from itertools import count

def plot_hull(data, hull):
    """
        Simple function to plot the Convex hull for a given set of points
    """
    xdata=data[0]
    ydata=data[1]

    xhull=hull[0]
    yhull=hull[1]

    fig, ax = plt.subplots( figsize=(10,10) )

    ax.scatter(xdata, ydata, marker='.', color='g')
    ax.grid(True)

    ax.plot(xhull, yhull, color='r')

    plt.show()

def animate_hull(data, hull):
    """
        Function to plot the data points statically
        then animate the formation of the hull
    """
    xdata=data[0]
    ydata=data[1]

    xhull=hull[0]
    yhull=hull[1]

    # these lists will be updated with data and then plotted
    x=[]
    y=[]

    fig, ax = plt.subplots( figsize=(5,5) )

    # plot data points statically
    ax.scatter(xdata,ydata,marker='.', color='g')

    # animate the formation of the hull
    counter = count(0,1)
    def updater(i):
        idx = next(counter) # get next index
        x.append( xhull[idx] )
        y.append( yhull[idx] )
        ax.plot(x,y)


    ani = FuncAnimation(fig=fig, func=updater, interval=500)
    ani.save('hull.gif') # save the animation

    plt.show()



# Get the data from the respective files
xdata = []
ydata = []

xhull = []
yhull = []

# read the input coordinates
with open( "data.txt", 'r' ) as f:
    for line in f:
        point = list( map( int, line.split(',') ) )
        xdata.append( point[0] )
        ydata.append( point[1] )

# read the convex hull edges
with open( "hull.txt" , 'r' ) as f:
    for line in f:
        point = list( map(int, line.split(',')) )
        xhull.append( point[0] )
        yhull.append( point[1] )

# Plot the data

# simple static line plot
# plot_hull([xdata,ydata], [xhull,yhull])

# animated plot
animate_hull([xdata,ydata], [xhull,yhull])