class StandardDPSolver:
    def __init__(self, people_presence, first_temperature, temperature_out, count):
        self.p_p = people_presence
        self.t_first = first_temperature
        self.t_out = temperature_out
        self.cnt = count
        self.W_cache = [{} for _ in self.p_p]

    def W(self, stage, state):
        if stage >= len(self.p_p):
            return 0, None

        if int(state) in self.W_cache[stage]:
            return self.W_cache[stage][int(state)]

        best_w = None
        best_u = None
        e_heat = (0, 2, 4, 6, 8, 10)
        c_cost = (0, 12, 25, 43, 62, 83)
        for u in range(0, 6):
            if stage < self.cnt:
                wi = self.p_p[stage] * ((19 - state) ** 2) + c_cost[u] + self.W(stage + 1, state + 0.5 * (e_heat[u] - 0.2 * (state - self.t_out[stage])))[0]
                if best_w is None or wi < best_w:
                    best_w = wi
                    best_u = u
        self.W_cache[stage][int(state)] = (best_w, best_u)
        return best_w, best_u

    def restore_optimal(self):
        control = []
        state = self.t_first
        for stage in range(len(self.p_p)):
            u = self.W(stage, state)[1]
            control.append(u)
            state = state - u * self.p_p[stage]
        return control

    def solve(self):
        return self.W(0, self.t_first)[0], self.restore_optimal()


presence = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
temperature = [-12, -11, -11, -10, -10, -9, -9, -8, -8, -7, -7, -6]

smart_house = StandardDPSolver(presence, 17, temperature, 12)

solution = smart_house.solve()

print("Значение целевой функции:", solution[0], "\n",
      "Оптимальный план включения отопления:", solution[1])
