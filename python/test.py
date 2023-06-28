import tkinter as tk
import random
from time import time

class Creatures:
	def __init__(self, canvas):
		self.speed = 1
		self.size = 1
		self.x0 = random.randint(0, 1920 - (10 * self.size))
		self.y0 = random.randint(0, 1080 - (10 * self.size))
		self.canvas = canvas
		self.rect = canvas.create_rectangle(self.x0, self.y0, self.x0 + (10 * self.size), self.y0 - (10 * self.size), fill="black")

	def move(self, n):
		if n == 0:
			self.canvas.move(self.rect, 0, self.speed * self.speed)
		elif n == 1:
			self.canvas.move(self.rect, 0, -(self.speed) * self.speed)
		elif n == 2:
			self.canvas.move(self.rect, self.speed * self.speed, 0)
		elif n == 3:
			self.canvas.move(self.rect, -(self.speed) * self.speed, 0)

class Food:
	def __init__(self, canvas):
		self.x0 = random.randint(0, 1920 - (10 * self.size))
		self.y0 = random.randint(0, 1080 - (10 * self.size))

	def init_food(self):


def update_canvas():
    rectangle.move(random.randint(0, 5))
    window.after(10, update_canvas)  # Delay in milliseconds before the next update

window = tk.Tk()
window.geometry(f"1920x1080")

canvas = tk.Canvas(window, bg="white", bd=2, width=1900, height=1060)
canvas.pack()

food = []

rectangle = Creatures(canvas)

update_canvas()

window.mainloop()
