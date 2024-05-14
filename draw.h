
#ifndef DRAW_H
#define DRAW_H
void drawRect(Rect name,int color) {
    SDL_Rect square = { name.x*20, name.y*20, name.Size - 1 , name.Size - 1 };
    if( color == RED )
    {
        SDL_SetRenderDrawColor(renderer, 232,43, 43, 255);
    }
    else if( color == GREEN)
    SDL_SetRenderDrawColor(renderer, 0,255,0, 255);
    if( color == YELLOW)
    SDL_SetRenderDrawColor(renderer, 255,255,0, 255);
    SDL_RenderFillRect(renderer, &square);
}
// Hàm vẽ hình tròn
void drawCircle(SDL_Renderer* renderer, Rect name, int radius) {
    // Vẽ từng dòng ngang của hình tròn
    SDL_SetRenderDrawColor(renderer, 232,43, 43, 255);
    for (int y = -radius; y <= radius; ++y) {
        // Tính toán giới hạn ngang tương ứng cho dòng hiện tại
        int x1 = name.x*20 - (int)(sqrt(radius * radius - (y * y)));
        int x2 = name.x*20 + (int)(sqrt(radius * radius - (y * y)));

        // Vẽ một dòng ngang từ x1 đến x2
        SDL_RenderDrawLine(renderer, x1, name.y*20 + y, x2, name.y*20+ y);
    }
}

#endif // DRAW_H

