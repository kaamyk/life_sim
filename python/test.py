import tkinter as tk
import random
import time

SC_WIDTH = 1920
SC_HEIGHT = 1080

def update_canvas():
	for creature in population:
		creature.move(random.randint(0, 5))
	window.after(10, update_canvas)
	
# Initiate window
window = tk.Tk()
window.geometry(f"1920x1080")

# Initiate environment
env = tk.Canvas(window, bg="white", bd=2, width=1900, height=1060)
env.pack()

population = []
f = []

# Instantiate the food class
food = Food(env);
food.initiate(env)
creature = Creatures(env)

creature.birth(env)

update_canvas()

window.mainloop()
