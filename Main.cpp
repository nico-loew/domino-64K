#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <glm/glm.hpp>

int main( int, char** )
{
	SDL_Init( SDL_INIT_VIDEO );

	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 24 );

	SDL_Window* window = SDL_CreateWindow( "Domino", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL );
	if( !window )
	{
		SDL_Quit();
	}

	SDL_GLContext context = SDL_GL_CreateContext( window );
	
	glewExperimental = GL_TRUE;

	if( glewInit() != GLEW_OK )
	{
		SDL_DestroyWindow( window );
		SDL_Quit();
	}
	
	SDL_GL_SetSwapInterval( 0 ); // no vsync

	SDL_Event event;
	bool run = true;
	glClearColor( 1.0f, 0.0f, 0.0f, 1.0f );

	glm::vec3 test( 2.0f, 2.0f, 2.0f );

	while( run )
	{
		while( SDL_PollEvent( &event ) )
		{
			if( event.type == SDL_QUIT )
				run = false;
		}

		glClear( GL_COLOR_BUFFER_BIT );

		SDL_GL_SwapWindow( window );
	}

	SDL_GL_DeleteContext( context );
	SDL_DestroyWindow( window );
	SDL_Quit();
	return 0;
}