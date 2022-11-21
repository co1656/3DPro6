#include <iostream>
#include <cmath>

using namespace std;

class mat4//4*4행렬
{
public: //외부에서 접근 가능하도록
	float mat[4][4];

	mat4() { //  행렬 생성자
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				mat[i][j] = 0; // 멤버 변수 초기화
			}
		}
	}

	mat4(float a1, float b1, float c1, float d1, float e1, float f1, float g1, float h1, float i1, float j1, float k1, float l1, float m1, float n1, float o1, float p1)
	{
		mat[0][0] = a1;
		mat[0][1] = b1;
		mat[0][2] = c1;
		mat[0][3] = d1;
		mat[1][0] = e1;
		mat[1][1] = f1;
		mat[1][2] = g1;
		mat[1][3] = h1;
		mat[2][0] = i1;
		mat[2][1] = j1;
		mat[2][2] = k1;
		mat[2][3] = l1;
		mat[3][0] = m1;
		mat[3][1] = n1;
		mat[3][2] = o1;
		mat[3][3] = p1;
	}

	mat4 identity_matrix()//단위행렬
	{
		return mat4(
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1);
	}

	mat4 transpose_matrix() //전치행렬로 변환
	{
		mat4 mm4;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				mm4.mat[i][j] = mat[j][i];
			}
		}
		return mm4;
	}
};

class mat3//3*3행렬
{
public: //외부에서 접근 가능하도록
	float mat[3][3];

	mat3() { //  행렬 생성자
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				mat[i][j] = 0; // 멤버 변수 초기화
			}
		}
	}

	mat3(float a, float b, float c, float d, float e, float f, float g, float h, float i)
	{
		mat[0][0] = a;
		mat[0][1] = b;
		mat[0][2] = c;
		mat[1][0] = d;
		mat[1][1] = e;
		mat[1][2] = f;
		mat[2][0] = g;
		mat[2][1] = h;
		mat[2][2] = i;
	}

	mat3 identity_matrix()//단위행렬
	{
		return mat3(
			1, 0, 0,
			0, 1, 0,
			0, 0, 1);
	}

	mat3 transpose_matrix() //전치행렬로 변환
	{
		mat3 mm;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				mm.mat[i][j] = mat[j][i];
			}
		}
		return mm;
	}
};

class vec3 //3*1
{
public: //외부접근가능
	float x, y, z;

	float vec[3] = { x,y,z }; //2차원배열 생성

	vec3() //초기배열
	{
		x = 0;
		y = 0;
		z = 1;
	}

	vec3(float x1, float y1, float z1)
	{
		x = x1;
		y = y1;
		z = z1;
	}
};

class vec1x3 //1*3
{
public: //외부접근가능

	float vec[1][3]; //2차원배열 생성

	vec1x3() //배열 초기화
	{
		vec[0][0] = 0;
		vec[1][0] = 0;
		vec[2][0] = 1;
	}

	vec1x3(float x2, float y2, float z2)
	{
		vec[0][0] = x2;
		vec[1][0] = y2;
		vec[2][0] = z2;
	}
};

class vec1x4 //1*4
{
public: //외부접근가능

	float vec[1][4]; //2차원배열 생성

	vec1x4() //배열 초기화
	{
		vec[0][0] = 0;
		vec[1][0] = 0;
		vec[2][0] = 0;
		vec[3][0] = 1;
	}

	vec1x4(float x3, float y3, float z3, float w3)
	{
		vec[0][0] = x3;
		vec[1][0] = y3;
		vec[2][0] = z3;
		vec[3][0] = w3;
	}
};

class vec4 //4*1
{
public: //외부접근가능
	float x, y, z, w;

	float vec[4] = { x,y,z,w }; //2차원배열 생성

	vec4() //초기배열
	{
		x = 0;
		y = 0;
		z = 0;
		w = 1;
	}

	vec4(float x4, float y4, float z4, float w4)
	{
		x = x4;
		y = y4;
		z = z4;
		w = w4;
	}
};

const vec3 operator * (const vec3 vec, const mat3 mm) //31벡터,33행렬 곱셈 계산
{
	vec3 vv;
	mat3 ma = mm;

	vv.x = ma.mat[0][0] * vec.x + ma.mat[1][0] * vec.y + ma.mat[2][0] * vec.z;
	vv.y = ma.mat[0][1] * vec.x + ma.mat[1][1] * vec.y + ma.mat[2][1] * vec.z;
	vv.z = ma.mat[0][2] * vec.x + ma.mat[1][2] * vec.y + ma.mat[2][2] * vec.z;

	return vv;
}

const mat3 operator * (const mat3& mb, const mat3& mc) //33행렬 곱셈 계산
{
	mat3 m1;
	mat3 m2 = mc;

	m1.mat[0][0] = m1.mat[0][0] * m2.mat[0][0] + m1.mat[0][0] * m2.mat[1][0] + m1.mat[0][0] * m2.mat[2][0];
	m1.mat[1][1] = m1.mat[1][1] * m2.mat[0][1] + m1.mat[1][1] * m2.mat[1][1] + m1.mat[1][1] * m2.mat[2][1];
	m1.mat[2][2] = m1.mat[2][2] * m2.mat[0][2] + m1.mat[2][2] * m2.mat[1][2] + m1.mat[2][2] * m2.mat[2][2];

	return m1;
}

const vec4 operator * (const vec4 vec, const mat4 mm4) //41벡터,44행렬 곱셈 계산
{
	vec4 v4;
	mat4 m4 = mm4;

	v4.x = m4.mat[0][0] * vec.x + m4.mat[1][0] * vec.y + m4.mat[2][0] * vec.z + m4.mat[3][0] * vec.w;
	v4.y = m4.mat[0][1] * vec.x + m4.mat[1][1] * vec.y + m4.mat[2][1] * vec.z + m4.mat[3][1] * vec.w;
	v4.z = m4.mat[0][2] * vec.x + m4.mat[1][2] * vec.y + m4.mat[2][2] * vec.z + m4.mat[3][2] * vec.w;
	v4.w = m4.mat[0][3] * vec.x + m4.mat[1][3] * vec.y + m4.mat[2][3] * vec.z + m4.mat[3][3] * vec.w;

	return v4;
}

const mat4 operator * (const mat4& mb, const mat4& mc4) //44행렬 곱셈 계산
{
	mat4 m41;
	mat4 m42 = mc4;

	m41.mat[0][0] = m41.mat[0][0] * m42.mat[0][0] + m41.mat[0][0] * m42.mat[1][0] + m41.mat[0][0] * m42.mat[2][0] + m41.mat[0][0] * m42.mat[3][0];
	m41.mat[1][1] = m41.mat[1][1] * m42.mat[0][1] + m41.mat[1][1] * m42.mat[1][1] + m41.mat[1][1] * m42.mat[2][1] + m41.mat[1][1] * m42.mat[3][1];;
	m41.mat[2][2] = m41.mat[2][2] * m42.mat[0][2] + m41.mat[0][0] * m42.mat[1][2] + m41.mat[0][0] * m42.mat[2][2] + m41.mat[2][2] * m42.mat[3][2];;
	m41.mat[3][3] = m41.mat[3][3] * m42.mat[0][2] + m41.mat[0][0] * m42.mat[1][2] + m41.mat[0][0] * m42.mat[2][2] + m41.mat[3][3] * m42.mat[3][3];;

	return m41;
}


void matrix()
{
	vec3 v(1, 1, 1);

	mat3 T = mat3(1, 0, 0, //x로 3, y로 5 이동
		0, 1, 0,
		3, 5, 1);

	mat3 R = mat3(cos(3.14 / 6), -sin(3.14 / 6), 0, //30도 회전
		sin(3.14 / 6), cos(3.14 / 6), 0,
		0, 0, 1);

	mat3 S = mat3(2, 0, 0, //크기 2배 증가
		0, 2, 0,
		0, 0, 1);

	vec3 p = v * T * R * S; //연산

	cout << p.x << ", " << p.y << ", " << p.z << endl; //결과값 출력
}

