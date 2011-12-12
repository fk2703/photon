#include "Viewport.h"


Viewport::Viewport(int iResolution, unsigned int iMaxPhotons)
{
	Resolution = iResolution;
	MaxPhotons = iMaxPhotons;
	Matrix = new std::vector<float>(Resolution*Resolution);
}

Viewport::~Viewport(void)
{
	delete Matrix;
}

void Viewport::OneStep(void)
{
	Particles &pPhotons_ref = pPhotons;
	sSuns.Shine(pPhotons_ref);
	pPhotons.Move();
}



/*
void inline add_photon(deque<photon>& photons, float x, float y, float z, float x1, float y1, float z1, float bright)
{
	photon c;
	c.x = x;
	c.y = y;
	c.z = z;
	c.x1 = x1;
	c.y1 = y1;
	c.z1 = z1;
	c.bright = bright;

	norm_photon(&c);
	photons.push_back(c);
	
}

void inline norm_photon(photon *temp)
{
	float len = pow(temp->x1, 2) + pow(temp->y1, 2) + pow(temp->z1, 2); 
	len = pow(len, (float) 0.5);
	float scale;
	if (len == 0) scale = 0; else scale = CSPEED/len;

	temp->x1 = temp->x1*scale;
	temp->y1 = temp->y1*scale;
	temp->z1 = temp->z1*scale;
}



sun *new_sun(float x, float y, float z)
{
	sun *temp;
	temp = (sun *) calloc(1, sizeof(sun));
	temp->next = NULL;
	temp->prev = NULL;
	temp->x = x;
	temp->y = y;
	temp->z = z;
	return temp;
}

sun *add_sun(sun *temp, float x, float y, float z)
{
	sun *curr;
	if (temp!= NULL)
	{
		curr = find_last_sun(temp);
		curr->next = new_sun(x, y, z);
		curr->next->prev = curr;
		return curr->next;
	}
	else
	{
		return new_sun(x, y, z);
	}
}

sun *find_last_sun(sun *temp)
{
	if (temp != NULL)
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	return temp;
}

sun *find_first_sun(sun *temp)
{
	while(temp->prev != NULL)
	{
		temp = temp->prev;
	}
	return temp;
}

int step(deque<photon>& photons, float *MATRIX)
{
	deque<photon>::iterator iter = photons.begin();
	
	float persy, persz;
	float size = 9;
	float res = RESOLUTION/size;

	while (iter!= photons.end())
	{

		if ((iter->y < size + CSPEED)&&(iter->x < size + CSPEED)&&(iter->y > -CSPEED)&&(iter->x > -CSPEED))
		if ((abs(iter->x) < DEPTH)||(abs(iter->x + iter->x1) < DEPTH))
		{
			persy = iter->y + iter->x1/(iter->y1*iter->x);
			persz = iter->z + iter->x1/(iter->z1*iter->x);

			if ((persy < size)&&(persy > 0))
			if ((persz < size)&&(persz > 0))
			{
				MATRIX[(int) ((persy*res))*RESOLUTION + (int)(persz*res)] += iter->bright;
			}
		}

		
		step_photon(&(*iter));
		if(brig_dist_check(&(*iter)) == PHOTON_UNFIT)
			while (brig_dist_check(&(*iter)) == PHOTON_UNFIT) {iter = photons.erase(iter);}
		else iter++;
	}

	return photons.size();
}

void inline step_photon(photon *temp)
{
	temp->x += temp->x1;
	temp->y += temp->y1;
	temp->z += temp->z1;
}

int inline brig_dist_check(photon *temp)
{
	int bad = 0;
	float brig = 0.0001, dist = MAX_DIST;

	while ((abs(temp->x) > dist)||(abs(temp->y) > dist)||(abs(temp->z) > dist)||(temp->bright < brig))
	{
		return PHOTON_UNFIT;
	}
	return PHOTON_FIT;
}

int shine(sun *suns, deque<photon> &photons)
{
	int x, y, z;
	float br;
	int i = 0;
	while (suns != NULL)
	{
		i++;
		
		for (int j = 0; j < SHINE_PER_STEP; j++)
		{
		
			do{
				x = rand() - RAND_MAX/2;
				y = rand() - RAND_MAX/2;
				z = rand() - RAND_MAX/2;
			}while ((x == 0)&&(y == 0)&&(z == 0));
			
			br = BRIGHT;((int) rand()%1024)/1024.0;
			add_photon(photons, suns->x, suns->y, suns->z, (float)x, (float)y, (float)z, (float)br);
		}
		suns = suns->next;
	}
	return i;
}

*/