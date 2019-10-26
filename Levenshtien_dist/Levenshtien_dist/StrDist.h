#pragma once
#include <string>
#include <vector>

namespace helpers {
	int LevenshtienDist(std::string from, std::string to) {
		int i, j, l1, l2, track, temp;
		l1 = from.size();
		l2 = to.size();
		std::vector< std::vector< int > > dist{ uint16_t(l2 + 1) , std::vector<int>(l1 + 1 , 0) };
		for (i = 0; i <= l1; i++) {
			dist[0][i] = i;
		}
		for (j = 0; j <= l2; j++) {
			dist[j][0] = j;
		}
		for (j = 1; j <= l1; j++) {
			for (i = 1; i <= l2; i++) {
				if (from[j - 1] == to[i - 1]) {
					track = 0;
				}
				else {
					track = 1;
				}
				temp = std::fmin((dist[i - 1][j] + 1), (dist[i][j - 1] + 1));
				dist[i][j] = std::fmin(temp, (dist[i - 1][j - 1] + track));
			}
		}
		return dist[l2][l1];
	}
}