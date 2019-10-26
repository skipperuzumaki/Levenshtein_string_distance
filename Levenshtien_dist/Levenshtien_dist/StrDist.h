#pragma once
#include <string>
#include <vector>
#include <algorithm>

namespace helpers {
	int LevenshtienDist(std::string _Source, std::string _Target) {
		uint8_t i, j, l1, l2, track, temp;
		uint8_t q1 = 1;
		uint8_t q0 = 0;
		l1 = uint8_t(_Source.size());
		l2 = uint8_t(_Target.size());
		std::vector< std::vector< int > > dist{ uint64_t(l2 + q1) , std::vector<int>(l2 + q1 , q0) };
		for (i = 0; i <= l1; i++) {
			dist[0][i] = int(i);
		}
		for (j = 0; j <= l2; j++) {
			dist[j][0] = int(j);
		}
		for (j = 1; j <= l1; j++) {
			for (i = 1; i <= l2; i++) {
				if (_Source[j - q1] == _Target[i - q1]) {
					track = 0;
				}
				else {
					track = 1;
				}
				temp = std::min((dist[i - q1][j] + 1), (dist[i][j - q1] + 1));
				dist[i][j] = int(std::min(temp, uint8_t(dist[i - q1][j - q1] + track)));
			}
		}
		return dist[l2][l1];
	}
}