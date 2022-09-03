@LunaUI
D3DXMATRIX projection, view, world;
	ModelInfo_t* pPlayer = new ModelInfo_t;
	D3DXVECTOR3 pOut(0, 0, 0), pV(0, 0, 0);

	pDevice->GetViewport(&g_ViewPort);
	pDevice->GetTransform(D3DTS_PROJECTION, &projection);
	pDevice->GetTransform(D3DTS_VIEW, &view);
	pDevice->GetTransform(D3DTS_WORLD, &world);

	D3DXVec3Project(&pOut, &pV, &g_ViewPort, &projection, &view, &world);

	if (pOut.z < 1)
	{
		pPlayer->Position2D.x = pOut.x;
		pPlayer->Position2D.y = pOut.y;
	}
	ModelInfo.push_back(pPlayer);