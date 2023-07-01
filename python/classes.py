class Creatures:
	def __init__(self, env):
		self.id = 1
		self.speed = 1
		self.size = 1
		self.x0 = random.randint(0, SC_WIDTH - (10 * self.size))
		self.y0 = random.randint(0, SC_HEIGHT - (10 * self.size))
		self.env = env
		self.rect = env.create_rectangle(self.x0, self.y0, self.x0 + (10 * self.size), self.y0 - (10 * self.size), fill="black")

	def move(self, n):
		if n == 0:
			if self.y0 + (2 * self.speed) > SC_HEIGHT:
				self.env.move(self.rect, 0, -SC_HEIGHT)
				self.y0 += -SC_HEIGHT
			else:
				self.env.move(self.rect, 0, 2 * self.speed)
				self.y0 += 2 * self.speed
		elif n == 1:
			if self.y0 - (2 * self.speed) < 0:
				self.env.move(self.rect, 0, SC_HEIGHT)
				self.y0 += SC_HEIGHT
			else:
				self.env.move(self.rect, 0, -2 * self.speed)
				self.y0 += -2 * self.speed
		elif n == 2:
			if (self.x0 + (2 * self.speed) > SC_WIDTH):
				self.env.move(self.rect, -SC_WIDTH, 0);
				self.x0 += -SC_WIDTH
			else:
				self.env.move(self.rect, 2 * self.speed, 0)
				self.x0 += 2 * self.speed
		elif n == 3:
			if self.x0 - (2 * self.speed) < 0:
				self.env.move(self.rect, SC_WIDTH)
				self.x0 += SC_WIDTH
			else:
				self.env.move(self.rect, -2 * self.speed, 0)
				self.x0 += -2 * self.speed

	def birth(self, env):
		population.append(Creatures(env))

class Food:
	def __init__(self, env):
		self.x0 = random.randint(0, 1920 - 3)
		self.y0 = random.randint(0, 1080 - 3)
		self.nb = 0
		self.env = env
		self.particule = env.create_rectangle(self.x0, self.y0, self.x0 + 3, self.y0 - 3, fill="red")

	def initiate(self, env):
		if (self.nb < 150):
			f.append(Food(env))
			self.nb += 1
			print (self.nb)
			self.env.after(1, self.initiate, env)

